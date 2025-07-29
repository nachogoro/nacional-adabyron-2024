#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// Constantes para representar "infinito"
constexpr ll INF = std::numeric_limits<ll>::max();
constexpr double INF_D = std::numeric_limits<double>::max();

// Estructura para representar una arista en el grafo
struct Edge {
	int to; // nodo destino
	int b;  // belleza del camino
	int w;  // tiempo que tarda en recorrerse
};

// Clase que representa un grafo dirigido o no dirigido
class Graph {
public:
	Graph(int v) : adj(v) {}

	// Agrega una arista bidireccional entre 'from' y 'to'
	void add_edge_bidirectional(int from, int to, int b, int w) {
		adj[from].push_back({to, b, w});
		adj[to].push_back({from, b, w});
	}

	// Agrega una arista unidireccional
	void add_edge(int from, int to, int b, int w) {
		adj[from].push_back({to, b, w});
	}

	// Ejecuta Dijkstra desde el nodo 'target' para calcular distancia mínima a él
	vector<ll> dijkstra(int target) const {
		priority_queue<pair<int, int>> q; // (distancia negativa, nodo)
		vector<bool> processed(adj.size(), false);
		vector<ll> distance(adj.size(), INF);
		distance[target] = 0;

		q.push({0, target});
		while (!q.empty()) {
			int a = q.top().second;
			q.pop();
			if (processed[a]) continue;
			processed[a] = true;
			for (auto u : adj[a]) {
				int neighbor = u.to;
				int w = u.w;
				if (distance[a] + w < distance[neighbor]) {
					distance[neighbor] = distance[a] + w;
					q.push({-distance[neighbor], neighbor});
				}
			}
		}
		return distance;
	}

	vector<vector<Edge>> adj; // Lista de adyacencia del grafo
};

// Determina si es posible alcanzar dst desde src con promedio de belleza/tiempo ≥ avg
bool is_obtainable(Graph& g, int src, int dst, double avg) {
	auto& adj = g.adj;
	int n = adj.size();

	// Convertimos cada arista a un "costo modificado": avg*w - b
	vector<tuple<int, int, double>> edges;
	for (int node = 0; node < adj.size(); ++node) {
		for (auto& edge : adj[node]) {
			edges.emplace_back(node, edge.to, avg * edge.w - edge.b);
		}
	}

	// Ejecutamos Bellman-Ford con esos costos
	vector<double> distance(n, INF_D);
	distance[src] = 0;
	for (int i = 1; i < n; ++i) {
		for (auto edge : edges) {
			int from, to;
			double weight;
			tie(from, to, weight) = edge;
			distance[to] = min(distance[to], distance[from] + weight);
		}
	}

	// Si el costo total es ≤ 0, ese promedio es alcanzable
	return distance[dst] <= 0;
}

// Resuelve una consulta para obtener el mayor promedio posible entre src y dst
void solve_query(Graph &g, int src, int dst) {
	auto distance = g.dijkstra(dst); // distancias a dst
	auto& adj = g.adj;

	// Creamos un nuevo grafo dirigido donde solo conservamos aristas que
	// acercan al destino (disminuyen la distancia a dst)
	Graph gp(adj.size());
	for (int node = 0; node < adj.size(); ++node) {
		for (auto edge : adj[node]) {
			if (distance[node] > distance[edge.to]) {
				gp.add_edge(node, edge.to, edge.b, edge.w);
			}
		}
	}

	auto& adjp = gp.adj;

	// Buscamos el mejor promedio posible con búsqueda binaria
	double left = INF_D;
	double right = 0;
	const double epsilon = 10E-7;

	// Inicializamos los extremos de búsqueda binaria
	for (int from = 0; from < adjp.size(); ++from) {
		for (auto edge : adjp[from]) {
			double avg = (double) edge.b / edge.w;
			if (avg > right) right = avg + 10 * epsilon;
			if (avg < left) left = avg;
		}
	}

	// Búsqueda binaria del mayor promedio alcanzable
	while (right - left >= epsilon) {
		double middle = (right + left) / 2;
		if (is_obtainable(gp, src, dst, middle)) {
			left = middle;
		} else {
			right = middle;
		}
	}

	cout << left << "\n"; // respuesta con 6 decimales
}

// Procesa una instancia del problema con n nodos y m aristas
void solve(int n, int m) {
	Graph g(n);
	for (int i = 0; i < m; ++i) {
		int from, to, w, b;
		cin >> from >> to >> w >> b;
		from--; to--; // Convertimos a base 0
		g.add_edge_bidirectional(from, to, b, w);
	}

	int q;
	cin >> q;

	for (int query = 0; query < q; ++query) {
		int src, dst;
		cin >> src >> dst;
		src--; dst--;
		solve_query(g, src, dst);
	}
	cout << "---\n"; // separador entre instancias
}

int main() {
	cout << fixed << setprecision(6); // 6 decimales fijos
	int n, m;

	while (cin >> n >> m) {
		solve(n, m);
	}
}

