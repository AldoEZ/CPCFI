def solve(n):
    resp = []
    for i in range(2,7):
        if n%i == 0:
            resp.append(i)
    if len(resp) > 0:
        print(*resp)
    else:
        print(-1)

t = int(input())
for _ in range(t):
    n = int(input())
    solve(n)
