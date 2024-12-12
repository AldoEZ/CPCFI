def solve(n, k, base):
    if n%k == 0 or n%base == 0:
        print("YES")
        return
    elif k%base == 1 and k <= n:
        print("YES")
    else:
        print("NO")

t = int(input())
base = 2
for _ in range(t):
    n, k = map(int, input().split())
    solve(n, k, base)
