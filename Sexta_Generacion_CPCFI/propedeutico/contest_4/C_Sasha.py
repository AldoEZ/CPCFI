def solve(n, ni):
    if len(ni) == 2:
        return ni[1] - ni[0]
    return (ni[1] - ni[0]) + solve(n, ni[1:])

t = int(input())
for _ in range(t):
    n = int(input())
    ni = list(map(int, input().split()))
    ni.sort()
    print(solve(n, ni))
