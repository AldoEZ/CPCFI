def solve(p, x, n):
    l = 1
    r = n + 1
    cont = 0
    while r - l > 1:
        m = (r + l) // 2
        print(p[m])
        if p[m] == x:
            return cont
        if p[m] <= x:
            l = m
        else:
            r = m
        print(p[m])
        cont += 1

t = int(input())
for _ in range(t):
    n, x  = map(int, input().split())
    p = list(map(int, input().split()))
    print(solve(p, x, n))


