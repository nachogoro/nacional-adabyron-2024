import java.util.*;

/* Clase que representa un grafo */
class Graph {
    /* Clase que representa una arista con peso saliente de un nodo. */
    public class Edge {
        final int dstNode;
        final int diameter;

        public Edge(int dstNode, int diameter) {
            this.dstNode = dstNode;
            this.diameter = diameter;
        }
    }

    /* Clase que representa un camino desde un cierto nodo */
    public class Path implements Comparable<Path> {
        public final int diameter;
        public final int currentNode;

        public Path(int diameter, int node) {
            this.currentNode = node;
            this.diameter = diameter;
        }

        /* Para usar en un montículo de máximos */
        @Override
        public int compareTo(Path o) {
            return Integer.compare(o.diameter, this.diameter);
        }
    }

    final public Map<Integer, List<Edge>> adjacencies = new HashMap<>();

    public void addEdge(int src, int dst, int diam) {
        adjacencies.computeIfAbsent(src, k -> new ArrayList<>()).add(new Edge(dst, diam));
    }

    /* Devuelve el diámetro máximo de cualquier ruta entre src y dst */
    public int maxDiameter(int src, int dst) {
        // Montículo de máximos para explorar los caminos de más a menos prometedor
        // (según diámetro)
        PriorityQueue<Path> heap = new PriorityQueue<>();
        heap.add(new Path(Integer.MAX_VALUE, src));

        // Almacena el diámetro más grande encontrado en una ruta que llega a un cierto nodo
        // Útil para evitar ciclos en el grafo o recalcular caminos peores que otros ya vistos
        Map<Integer, Integer> maxDiameterToNode = new HashMap<>();
        maxDiameterToNode.put(src, Integer.MAX_VALUE);

        int largestDiameterFound = Integer.MIN_VALUE;
        while (!heap.isEmpty()) {
            Path p = heap.poll();

            // Este camino, que es el más prometedor de todos los restantes, no es mejor
            // que otro ya encontrado, no hace falta seguir buscando.
            if (p.diameter <= largestDiameterFound) break;

            // Este camino ha llegado al destino, actualizamos el mejor diámetro encontrado
            if (p.currentNode == dst) {
                largestDiameterFound = Math.max(largestDiameterFound, p.diameter);
                continue;
            }

            // Si el nodo actual de este camino no conecta con ningún otro, no podemos continuar
            if (!adjacencies.containsKey(p.currentNode)) continue;

            for (Edge edge : adjacencies.get(p.currentNode)) {
                int newDiameter = Math.min(p.diameter, edge.diameter);

                // Sólo continuamos el path a través de esta arista si nos permitiría llegar
                // potencialmente a un diámetro mejor que el encontrado.
                if (newDiameter > maxDiameterToNode.getOrDefault(edge.dstNode, Integer.MIN_VALUE)) {
                    maxDiameterToNode.put(edge.dstNode, newDiameter);
                    heap.add(new Path(newDiameter, edge.dstNode));
                }
            }
        }

        return largestDiameterFound == Integer.MIN_VALUE ? 0 : largestDiameterFound;
    }
}

public class LRyP {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            Graph g = new Graph();

            final int vertex = scanner.nextInt();
            final int edges = scanner.nextInt();

            for (int i = 0; i < edges; i++) {
                final int src = scanner.nextInt();
                final int dst = scanner.nextInt();
                final int d = scanner.nextInt();
                g.addEdge(src, dst, d);
            }

            final int src = scanner.nextInt();
            final int dst = scanner.nextInt();
            System.out.println(g.maxDiameter(src, dst));
        }
    }
}
