import java.util.Scanner;


class FenwickTree {
    private static int[] bit;

    public FenwickTree(int n) {
        bit = new int[n];
    }

    public FenwickTree(int[] a) {
        this(a.length);

        for (int i = 0; i < a.length; i++) {
            bit[i] += a[i];
            int r = i | (i + 1);

            if (r < a.length)
                bit[r] += bit[i];
        }
    }

    public int sum(int r) {
        int ret = 0;

        for (; r >= 0; r = (r & (r + 1)) - 1) {
            ret += bit[r];
        }

        return ret;
    }

    public void add(int index, int delta) {
        for (; index < bit.length; index = index | (index + 1))
            bit[index] += delta;
    }
}


public class E {
    private static final Scanner input = new Scanner(System.in);

    private static int binary_search_lower_bound(FenwickTree ft, long target, int lower, int upper) {
        while (upper - lower > 1) {
            int mid = (lower + upper) / 2;

            if (ft.sum(mid) < target)
                lower = mid;
            else
                upper = mid;
        }

        return upper;
    }

    public static void test(int[] sinfonias, int q) {
        int n = sinfonias.length;
        FenwickTree ft = new FenwickTree(n);

        long inicio_renum = 0;
        long final_renum = 1;

        int indice_sinfonia = 0;
        ft.add(sinfonias[indice_sinfonia], 1);

        while (q-- > 0) {
            long consulta = input.nextLong() - 1;

            while (consulta >= final_renum) {
                indice_sinfonia++;
                int huecos = ft.sum(n - 1) - ft.sum(sinfonias[indice_sinfonia]) + 1;
                ft.add(sinfonias[indice_sinfonia], 1);

                inicio_renum = final_renum;
                final_renum += huecos;
            }

            int id_sinfonia = binary_search_lower_bound(ft, ft.sum(sinfonias[indice_sinfonia]) + consulta - inicio_renum, -1, n - 1);
            boolean definitiva = ft.sum(id_sinfonia) == id_sinfonia + 1;

            System.out.println((definitiva ? "Es la " : "Fue la ") + (id_sinfonia + 1));
        }

        System.out.println("---");
    }

    public static void main(String[] args) {
        int n = input.nextInt();

        while (n != 0) {
            int[] sinfonias = new int[n];

            for (int i = 0; i < n; i++) {
                sinfonias[i] = input.nextInt() - 1;
            }

            int q = input.nextInt();

            test(sinfonias, q);

            n = input.nextInt();
        }
    }
}
