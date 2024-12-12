# cses
def solve(ni):
    movs = 0
    for i in range(1, len(ni)):
        if ni[i] < ni[i-1]:
            movs += (ni[i-1]-ni[i])
            ni[i] += (ni[i-1]-ni[i])
    return movs

n = int(input())
ni = list(map(int, input().split()))
print(solve(ni))
