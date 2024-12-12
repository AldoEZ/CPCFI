def solve(n, ni):
    if (min(ni) == 1) and (len(ni)%2 == 0):
        print("Bob")
    else:
        print("Alice")

t = int(input())
for _ in range(t):
    n = int(input())
    ni = set(map(int, input().split()))
    solve(n, ni)
    a = 'asdasd'
    a[0].upper