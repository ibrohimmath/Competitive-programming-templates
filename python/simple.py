import sys

inputln = sys.stdin.readline
println = sys.stdout.write

inputTest = False
# inputTest = True
def solve(test: int) -> None:
    pass

if __name__ == "__main__":
    tests = 1

    if inputTest:
        tests = int(input())

    for t in range(1, tests + 1):
        solve(t)
