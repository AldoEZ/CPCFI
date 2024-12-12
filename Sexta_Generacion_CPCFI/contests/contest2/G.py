def solve(ni):
    if len(set(ni)) == 1:
        return len(ni)
    

t = int(input())
for _ in range(t):
    n = int(input())
    ni = list(map(int, input().split()))
    ni.sort()
    print(solve(ni))
