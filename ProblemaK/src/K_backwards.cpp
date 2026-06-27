#include <bits/stdc++.h>
using namespace std;

template <class T, class Compare = std::less<T>>
class MonotonicDeque {
public:
    explicit MonotonicDeque(std::size_t k, Compare cmp = Compare())
        : k_(k), cmp_(cmp) {}

    // Añade el valor v etiquetado con el índice i. Expulsa el insertado k
    // inserciones antes (si sigue vivo) y mantiene la monotonía. O(1) amortizado.
    void push(int i, const T& v) {
        const long long ord = inserted_++;
        // 1) Mantener la monotonía: fuera los candidatos peores por la cola.
        while (!dq_.empty() && !cmp_(dq_.back().val, v))
            dq_.pop_back();
        dq_.push_back({i, v, ord});
        // 2) Expulsar lo que cayó fuera de la ventana de k inserciones.
        //    El frente es el más antiguo, así que basta mirarlo (a lo sumo uno).
        while (dq_.front().ord <= inserted_ - 1 - (long long)k_)
            dq_.pop_front();
    }

    int      minIndex() const { return dq_.front().idx; }   // índice/etiqueta del mínimo
    const T& minValue() const { return dq_.front().val; }   // valor mínimo

    bool        empty() const { return dq_.empty(); }
    std::size_t size()  const { return dq_.size(); }        // nº de candidatos vivos

private:
    struct Node { int idx; T val; long long ord; };
    std::size_t k_;
    Compare cmp_;
    long long inserted_ = 0;     // total de inserciones (orden de inserción)
    std::deque<Node> dq_;
};

void solve() {
	int N, K;
	cin >> N >> K;
	vector<long long> v(N);
	vector<long long> prefix(N);   // prefix[i] = v[0] + ... + v[i]  (suma prefija inclusiva)
	long long sum = 0;
	for (int i = 0; i < N; ++i) {
		cin >> v[i];
		sum += v[i];
		prefix[i] = sum;
	}

	// dp[i] = máxima puntuación obtenible jugando a partir de la partida i,
	// suponiendo que llegamos "frescos" (la partida i-1 no se jugó, así que la
	// racha de consecutivas empieza de cero en i). La respuesta es dp[0].
	//
	// Si jugamos la partida i, debemos saltarnos una partida j con i < j <= i+K
	// para no encadenar más de K consecutivas. Eso aporta sum(i..j-1) + dp[j+1],
	// donde sum(i..j-1) = v[i] + (prefix[j-1] - prefix[i]). Por tanto:
	//
	//   dp[i] = max( dp[i+1],                                  // saltarse la partida i
	//                v[i] - prefix[i] + max_{i<j<=i+K} (prefix[j-1] + dp[j+1]) )
	//
	// El término del máximo solo depende de j, así que lo guardamos en una cola
	// monótona indexada por j con valor (prefix[j-1] + dp[j+1]) = prefix[j]-v[j]+dp[j+1],
	// y consultamos el máximo de la ventana de los K últimos j en O(1).
	vector<long long> dp(N+1, 0);   // dp[N] = 0: no hay partidas más allá del final
	dp[N-1] = v[N-1];

	MonotonicDeque<long long, std::greater<long long>> mono_deque(K);
	mono_deque.push(N-1, prefix[N-1] - v[N-1] + dp[N]);

	// Para las K últimas partidas caben <= K consecutivas hasta el final, así que
	// lo óptimo es jugarlas todas (todas las puntuaciones son positivas).
	for (int j = 0; j < K; ++j) {
		int i = N - 1 - j;
		dp[i] = v[i] + dp[i+1];                          // dp[i] = sum(i..N-1)
		mono_deque.push(i, prefix[i] - v[i] + dp[i+1]);  // registramos i como posible j futuro
	}

	// Para el resto, jugar la partida i obliga a saltarse alguna de las K siguientes.
	for (int i = N-1 - K; i >= 0; --i) {
		// La ventana contiene ahora los candidatos j en [i+1, i+K].
		dp[i] = max(dp[i+1], v[i] - prefix[i] + mono_deque.minValue());
		mono_deque.push(i, prefix[i] - v[i] + dp[i+1]);
	}

	cout << dp[0] << "\n";
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		solve();
	}
}
