def solve(n, ni):
    punt = 0
    while (n > 0) and (len(ni) > 1):
        punt += min(ni[0], ni[1])
        ni = ni[2:]
    return punt

t = int(input())
for _ in range(t):
    n = int(input())
    ni = list(map(int, input().split()))
    ni.sort()
    print(solve(n, ni))
