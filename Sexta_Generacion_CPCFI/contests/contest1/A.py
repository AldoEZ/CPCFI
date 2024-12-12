def solve(ni, l):
    if len(ni) == 1:
        return max(l - ni[0], ni[0])
    maxi = ni[0]
    final = l - ni[-1]
    for i in range(1, len(ni)):
        if (ni[i] - ni[i-1]) > maxi:
            maxi = ni[i] - ni[i-1]
    return max(final, ni[0], maxi/2)

n, l = map(int, input().split())
ni = list(map(int, input().split()))
ni.sort()
print(solve(ni, l))
