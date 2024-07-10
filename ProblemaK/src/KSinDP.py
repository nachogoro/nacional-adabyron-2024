from collections import deque


# https://cp-algorithms.com/data_structures/stack_queue_modification.html#queue-modification-method-2
class MinimumQueue:
    def __init__(self) -> None:
        self._q: deque[tuple[int, int]] = deque()
        self._cnt_added = 0
        self._cnt_removed = 0

    def minimum(self) -> int:
        return self._q[0][0]

    def add(self, item) -> None:
        while self._q and self._q[-1][0] > item:
            self._q.pop()
        self._q.append((item, self._cnt_added))
        self._cnt_added += 1

    def remove(self) -> None:
        if self._q and self._q[0][1] == self._cnt_removed:
            self._q.popleft()
        self._cnt_removed += 1


def test(p: list[int], k: int) -> int:
    q = MinimumQueue()
    q.add(0)  # pierde[0] = 0

    for i, p_i in enumerate(p):
        # pierde[i + 1] = p_i + q.minimum()
        q.add(p_i + q.minimum())  # min(q) = min(pierde[j], i - k - 1 <= j <= i - 1)

        if i >= k:
            q.remove()

    return sum(p) - q.minimum()


def main():
    t = int(input())

    for _ in range(t):
        n, k = map(int, input().split())
        p = list(map(int, input().split()))

        print(test(p, k))


if __name__ == '__main__':
    main()
