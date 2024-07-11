import collections

MOD = 1_000_000_007


def test(disponibilidad: list[int]) -> int:
    n = len(disponibilidad)
    dp = [0] * (n + 1)

    disp = [-1] + disponibilidad
    bottlenecks = collections.deque([0])

    for i, d in enumerate(disponibilidad, 1):
        while disp[bottlenecks[-1]] >= d:
            bottlenecks.pop()

        bottlenecks.append(i)
        bottleneck = bottlenecks[-2]

        if d < 2:
            continue

        dp[i] = ((d - 1) * (i - bottleneck - 1)) % MOD
        dp[i] = (dp[i] + dp[bottleneck]) % MOD

        if disp[bottleneck] > 0:
            dp[i] = (dp[i] + disp[bottleneck] - 1) % MOD

    return sum(dp) % MOD


def main():
    while n := int(input()):
        disp = list(map(int, input().split()))
        print(test(disp))


if __name__ == '__main__':
    main()
