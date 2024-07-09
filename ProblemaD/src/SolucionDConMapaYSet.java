import java.util.*;

public class SolucionDConMapaYSet {
    private static boolean esEquilateral(String palabra) {
        HashMap<Character, Integer> frecuencia = new HashMap<>();

        for (char c : palabra.toCharArray()) {
            frecuencia.put(c, frecuencia.getOrDefault(c, 0) + 1);
        }

        Set<Integer> frecuenciasDistintas = new HashSet<>();
        for (int f : frecuencia.values()) {
            frecuenciasDistintas.add(f);
        }

        return frecuenciasDistintas.size() == 1;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        final int casos = Integer.parseInt(scanner.nextLine());

        for (int i = 0; i < casos; i++) {
            System.out.println(esEquilateral(scanner.nextLine()) ? "SI" : "NO");
        }
    }
}
