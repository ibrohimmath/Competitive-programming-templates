# import sys
# sys.setrecursionlimit(100000)

# from bisect import bisect_right

def solve(test_case: int) -> None:
    N, M, X = map(int, input().split())

    events = []
    for i in range(N):
        a, b, v = map(int, input().split())
        if a < b:
            events.append([(X - b) / v, -1, i]) 
            events.append([(X - a) / v, 1, i])
        else:
            events.append([(b - X) / v, -1, i])
            events.append([(a - X) / v, 1, i])

    temp = []
    ans = [0] * M 
    A = list(map(int, input().split()))
    for t in range(M):
        events.append([A[t], 2, t])

    events.sort()
    # print(events)

    trains = 0
    for time, type, ind in events:
        if type == -1:
            trains += 1
        elif type == 1:
            trains -= 1
        else:
            temp.append(ind)

        if trains == 0:
            for ind in temp:
                ans[ind] = time
            temp = []

    print(*ans, sep='\n')

inputTest = False
def main():
    t = 1
    if inputTest:
        t = int(input())

    for i in range(1, t + 1):
        solve(i)


main()