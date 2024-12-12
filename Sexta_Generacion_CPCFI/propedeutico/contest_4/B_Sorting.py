def solve(x, y):
    print(min(x, y), max(x, y))

t = int(input())
for _ in range(t):
    x, y = map(int, input().split())
    solve(x, y)
