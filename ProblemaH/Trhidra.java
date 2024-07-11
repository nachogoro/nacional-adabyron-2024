import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Trhidra {
    private static final long MOD = 1_000_000_007L;
    private static final Map<Integer, Long> cache = new HashMap<>();

    private static long cortesCabeza(final int nivel, final int regen) {
        // Si ya hemos calculado antes los cortes para este nivel, reutilizarlos
        if (cache.containsKey(nivel)) return cache.get(nivel);

        long resultado = 1;
        long termino = 1;
        for (int i = 1; i <= nivel - 1; i++) {
            termino *= regen;
            termino %= MOD;

            resultado += termino;
            resultado %= MOD;
        }

        cache.put(nivel, resultado);
        return resultado;
    }

    private static class Nodo {
        public final ArrayList<Nodo> hijos = new ArrayList<>();
    }

    private static Nodo leerArbol(Scanner scanner) {
        Nodo raiz = new Nodo();

        final int numHijos = scanner.nextInt();
        for (int i = 0; i < numHijos; i++) {
            raiz.hijos.add(leerArbol(scanner));
        }

        return raiz;
    }

    /* Calcula el número de cortes necesario para acabar con todo el árbol de cabezas que empieza en raiz */
    private static long calcularCortes(Nodo raiz, int nivel, int regen) {
        if (raiz.hijos.isEmpty()) {
            // Nodo hoja
            return cortesCabeza(nivel, regen);
        } else {
            // Nodo intermedio. Hay que contar los cortes del intermedio
            // y de todos sus hijos.
            // OJO, al cortar la última cabeza de la raíz no se regenera una nueva,
            // a diferencia del resto de nodos no-hoja
            long resultado;
            if (nivel == 0) resultado = 0;
            else            resultado = cortesCabeza(nivel, regen);

            for (Nodo hijo : raiz.hijos) {
                resultado += calcularCortes(hijo, nivel + 1, regen);
                resultado %= MOD;
            }

            return resultado;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            final int regen = scanner.nextInt();
            if (regen == 0) break;

            cache.clear();
            final Nodo raiz = leerArbol(scanner);
            System.out.println(calcularCortes(raiz, 0, regen));
        }
    }
}