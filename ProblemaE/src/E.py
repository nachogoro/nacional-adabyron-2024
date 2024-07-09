import sys
from typing import *


# traducido de la implementación en: https://cp-algorithms.com/data_structures/fenwick.html
class FenwickTree:
    def __init__(self, a: list[int]):
        self.bit = [0] * len(a)

        for i, a_i in enumerate(a):
            self.bit[i] += a_i
            r = i | (i + 1)

            if r < len(a):
                self.bit[r] += self.bit[i]

    def __len__(self):
        return len(self.bit)

    def sum(self, r: int) -> int:
        ret = 0

        while r >= 0:
            ret += self.bit[r]
            r = (r & (r + 1)) - 1

        return ret

    def add(self, index: int, delta: int) -> None:
        while index < len(self):
            self.bit[index] += delta
            index = index | (index + 1)


def binary_search_lower_bound(f: Callable[[int], int], x: int, lower: int, upper: int) -> int:
    while upper - lower > 1:
        mid = (lower + upper) // 2

        if f(mid) < x:
            lower = mid
        else:
            upper = mid

    return upper


def test(sinfonias: list[int], consultas: int):
    n = len(sinfonias)
    ft = FenwickTree([0] * n)

    inicio_renum = 0  # índice inicial de la renumeración (inclusivo)
    final_renum = 0  # índice final de la renumeración (exclusivo)

    sinfonias_iter = iter(sinfonias)
    nueva_sinfonia: int  # identificador de la última sinfonía descubierta

    for consulta in consultas:
        while consulta >= final_renum:
            # Añadimos una nueva sinfonía al catálogo
            nueva_sinfonia = next(sinfonias_iter)

            huecos = ft.sum(n - 1) - ft.sum(nueva_sinfonia) + 1  # Número de huecos generados por el descubrimiento de la nueva sinfonía
            ft.add(nueva_sinfonia, 1)

            # Actualizamos los rangos de la renumeración
            inicio_renum = final_renum
            final_renum += huecos

        id_sinfonia = binary_search_lower_bound(ft.sum, ft.sum(nueva_sinfonia) + consulta - inicio_renum, -1, n - 1)
        definitiva = ft.sum(id_sinfonia) == id_sinfonia + 1  # La numeración es definitiva si ya han aparecido todas las sinfonías anteriores

        yield id_sinfonia, definitiva


def main():
    while n := int(sys.stdin.readline().strip()):
        sinfonias = [int(i) - 1 for i in sys.stdin.readline().split()]  # pasar a 0-based indexing
        q = int(sys.stdin.readline().strip())
        consultas = (int(i) - 1 for i in sys.stdin.readline().split())

        for id, definitiva in test(sinfonias, consultas):
            print(f"{'Es' if definitiva else 'Fue'} la {id + 1}")

        print("---")


if __name__ == '__main__':
    main()
