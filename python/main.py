import sys
# sys.setrecursionlimit(100000)

# from bisect import bisect_right

inputln = sys.stdin.readline
def println(*args, sep=' ', end='\n'):
    sys.stdout.write(sep.join(map(str, args)) + end)

inputTest = True
# inputTest = False
def solve(test_case: int) -> None:
    print('hello')
    pass

def main():
    t = 1
    if inputTest:
        t = int(inputln())

    for i in range(1, t + 1):
        solve(i)

main()