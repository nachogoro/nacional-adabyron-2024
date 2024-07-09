#include <bits/stdc++.h>

using namespace std;

struct examen {
	int suma = 0;    // suma de notas de los alumnos en este examen
	int peso;        // peso final del examen
	int peso_max;    // peso máximo admitido
	int ind_entrada; // índice en la entrada

	/**
	 * Comparador de examenes, el menor es el que las notas * en conjunto han sido más bajas. Se usa para ordenar.
	 */
	bool operator<(const examen &ex2) const {
		return suma < ex2.suma;
	};
};

/**
 * Resolver el caso de prueba dado por el vector de exámenes.
 * Imprime el resultado tal como se pide.
 * @param exs vector de exámenes con la suma de notas y las horquillas leídas,
 * @param suma_pesos suma de los pesos asignados en los exámenes.
 * con el peso al mínimo.
 */
void resolver(vector<examen> &exs, int suma_pesos) {
	// ordenamos el vector (de peor resultado a mejor)
	sort(exs.begin(), exs.end());

	// subimos los pesos hasta que suma_pesos = 100
	int index = 0;
	while (suma_pesos < 100) {
		int falta  = 100 - suma_pesos;
		int subida = exs[index].peso_max - exs[index].peso;

		if (subida >= falta) {
			// podemos subir este examen todo lo que queramos
			exs[index].peso += falta;
			break;
		}
		else {
			// subimos lo máximo posible i vamos al próximo examen
			exs[index].peso += subida;
			suma_pesos += subida;
			index++;
		}
	}

	// desordenamos el vector para mostrarlo como nos lo han dado
	vector<int> pesos_orden(exs.size());
	for (examen& ex : exs)
		pesos_orden[ex.ind_entrada] = ex.peso;

	// mostramos el resultado
	for (int i = 0; i < exs.size(); i++) {
		if (i)
			cout << " ";
		cout << pesos_orden[i];
	}
	cout << endl;
}

int main(int argc, char *argv[]) {
	int n, m;
	while (cin >> n >> m) {
		vector<examen> exs(m);

		// leemos las notas de cada alumno
		while (n--) {
			for (int i = 0; i < m; i++) {
				int nota;
				cin >> nota;
				exs[i].suma += nota;
			}
		}

		// leemos las horquillas, asignando la inferior al peso
		int suma_pesos = 0;
		for (int i = 0; i < m; i++) {
			cin >> exs[i].peso >> exs[i].peso_max;
			exs[i].ind_entrada = i;
			suma_pesos += exs[i].peso;
		}

		// resolvemos este caso
		resolver(exs, suma_pesos);
	}
    return 0;
}
