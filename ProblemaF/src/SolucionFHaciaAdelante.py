"""
IDEA 1 - Recorrer la lista hacia adelante cambiando de candidato.

Esta idea consiste en recorrer las sabidurías de los magos en orden creciente, y cambiar de candidato si algún mago
tiene sabiduría mayor a la suma de todos sus predecesores.
"""


def test(s: list[int]) -> int:
    # ordenamos los magos por sabiduría en una lista de tuplas (posición inicial, sabiduría)
    s_sorted = sorted(enumerate(s, 1), key=lambda t: t[1])

    cum_wisdom = 0  # suma acumulada de la sabiduría de los magos anteriores al actual
    candidate = 0  # candidato a ganar

    for i, cur_wisdom in s_sorted:
        if cur_wisdom > cum_wisdom:
            candidate = i
        cum_wisdom += cur_wisdom

    return candidate


def main():
    t = int(input())

    for _ in range(t):
        n = int(input())
        s = list(map(int, input().split()))

        print(test(s))


if __name__ == '__main__':
    main()
