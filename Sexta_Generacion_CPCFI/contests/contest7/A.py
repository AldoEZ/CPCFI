def solve(n, a, b):
    i, j = 0, 0
    cont = 0
    while i < n and j < n:
        if b[j] < a[i]:
            a.append(b[i])
            a.pop(-1)
            j += 1
            cont += 1
        else:
            i += 1
            j += 1
    return cont

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    print(solve(n, a, b))