#!/usr/bin/env python

# Largest Perimeter Triangle


from typing import List


def solve(x: List[int]):
    x.sort()
    for i in range(len(x) - 1, 1, -1):
        if x[i] < x[i - 1] + x[i - 2]:
            return x[i] + x[i - 1] + x[i - 2]
    return 0


def main():
    x = [2, 1, 2]
    print(solve(x))


if __name__ == '__main__':
    main()
