"""
IDEA 2 - Recorrer la lista hacia atrás.

Esta idea consiste en recorrer las sabidurías de los magos en orden decreciente, y parar cuando encontremos un candidato
con sabiduría mayor a la suma de todos los anteriores.
"""


def test(s: list[int]) -> int:
    # ordenamos los magos en orden descendente de sabiduría en una lista de tuplas (posición inicial, sabiduría)
    s_sorted = sorted(enumerate(s, 1), key=lambda t: t[1], reverse=True)

    total = sum(s)
    suffix_sum = 0  # suma del mago actual y todos los más sabios

    for i, cur_wisdom in s_sorted:
        suffix_sum += cur_wisdom

        if cur_wisdom > total - suffix_sum:
            return i


def main():
    t = int(input())

    for _ in range(t):
        n = int(input())
        s = list(map(int, input().split()))

        print(test(s))


if __name__ == '__main__':
    main()
