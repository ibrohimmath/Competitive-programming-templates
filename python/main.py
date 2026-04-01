import sys
from typing import List
import heapq
# sys.setrecursionlimit(100000)

# from bisect import bisect_right
# from math import ceil, floor, log10, log2

inputln = sys.stdin.readline
def println(*args, sep=' ', end='\n'):
    sys.stdout.write(sep.join(map(str, args)) + end)

def leetcode():
    pass

# inputTest = True
inputTest = False
def solve(test_case: int) -> None:
    pass

    n = int(input())
    s = input()
    counter = {}
    counter[0] = 1
    ans = 0
    pref = 0
    for i in range(n):
        if s[i] == 'a':
            pref += 1
        else:
            pref -= 1
        ans += counter.get(pref, 0)
        counter[pref] = counter.get(pref, 0) + 1
    print(ans)


if __name__ == '__main__':
    t = 1

    if inputTest:
        t = int(inputln())

    for i in range(1, t + 1):
        solve(i)

    leetcode()
