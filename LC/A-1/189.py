# https://leetcode.com/problems/rotate-array/


from typing import List


def optimized(x: List[int], k: int):
    def reverse(a, b):
        while a < b:
            x[a], x[b] = x[b], x[a]
            a, b = a + 1, b - 1

    reverse(0, len(x) - 1)
    reverse(0, k - 1)
    reverse(k, len(x) - 1)


def naive(x: List[int], k: int):
    k %= len(x)
    while k:
        k -= 1
        a = x[-1]
        for i in range(len(x) - 1, 0, -1):
            x[i] = x[i - 1]
        x[0] = a


def main():
    k: int = 3
    x: list[int] = [1, 2, 3, 4, 5, 6, 7]
    optimized(x, k)
    print(x)


if __name__ == '__main__':
    main()
