def solve(n, c, ni):
    for i in range(1, n+1):
        ni[i-1] += i
    ni.sort()
    cont = 0
    for i in range(n):
        c -= ni[i]
        cont += 1
        if ((c == 0) or (c < ni[i+1])) and (i < n-2):
            return cont

t = int(input())
for _ in range(t):
    n, c = map(int, input().split())
    ni = list(map(int, input().split()))
    print(solve(n, c, ni))
