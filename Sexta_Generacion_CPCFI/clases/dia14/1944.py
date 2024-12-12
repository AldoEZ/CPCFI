def solve(n,k):
    if k >= n-1:
        print(1)
    else:
        print(n)

t = int(input())
for i in range(t):
    n, k = map(int,input().split())
    solve(n,k)
