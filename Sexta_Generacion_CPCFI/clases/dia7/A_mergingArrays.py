# codeforces

def solve(n, m, ni, mi):
    i, j = 0, 0
    while i < n and j < m:
        if ni[i] <= mi[j]:
            print(ni[i], end=" ")
            i += 1
        elif ni[i] >= mi[j]:
            print(mi[j], end=" ")
            j += 1
    while i < n:
        print(ni[i], end=" ")
        i += 1
    while j < m:
        print(mi[j], end=" ")
        j += 1

n, m = map(int, input().split())
ni = list(map(int, input().split()))
mi = list(map(int, input().split()))
solve(n, m, ni, mi)
