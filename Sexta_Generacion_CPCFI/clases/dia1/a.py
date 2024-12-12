def solve(k, a, b):
    i = 0
    while (len(b) > 0) and (min(a) <= k):
        n = b.index(min(b))
        k += b[n]
        b.pop(n)
        a.pop(n)    
    return k

t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    print(solve(k, a, b))
