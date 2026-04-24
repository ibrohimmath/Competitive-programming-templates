import sys
# sys.setrecursionlimit(1000000)

from datetime import date, datetime
from typing import Callable
# from typing import List

from math import ceil, floor, trunc, log10, log2
from functools import lru_cache, reduce, cmp_to_key

# from bisect import bisect_left, bisect_right
# import heapq

##################################################################################################
# Input/Output

inputln = sys.stdin.readline
def println(*args, sep=' ', end='\n'):
    sys.stdout.write(sep.join(map(str, args)) + end)

##################################################################################################
# Helpers

def debug(*x):
    global testMode
    if not testMode:
        return
    println(*x)

def Timer(func: Callable):
    def wrapper(*args, **kwargs):
        now = datetime.now()
        func(*args, **kwargs)
        endnow = datetime.now()
        print(f'Time taken {(endnow - now)}')

    return wrapper

##################################################################################################
# Leetcode



def leetcode():
    pass

##################################################################################################
# Solution


# testMode = True
testMode = False
# inputTest = True
inputTest = False
def solve(testCase: int) -> None:
    pass




# @Timer
def main():
    t = 1

    if inputTest:
        t = int(input())

    for i in range(1, t + 1):
        solve(i)

    leetcode()

if __name__ == '__main__':
    main()
