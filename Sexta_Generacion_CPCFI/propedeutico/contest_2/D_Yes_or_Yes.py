def solve(s):
    if s.upper() == 'YES':
        print("YES")
    else:
        print("NO")

t = int(input())
for _ in range(t):
    s = input()
    solve(s)
