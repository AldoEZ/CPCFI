def solve(n, ni):
    min = ni[0]
    cont = 0
    for num in ni:
        if num > min:
            cont += 1
    return cont

t = int(input())
for _ in range(t):
    n = int(input())
    ni = list(map(int, input().split()))
    ni.sort()
    print(solve(n, ni))
