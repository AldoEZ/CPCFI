def solve(n, l, r, ni):
    i, cont = 0, 0
    while i < n:
        if ni[i] <= r and ni[i] >= l:
            cont += 1
            i += 1
        elif ni[i] > r:
            i += 1
        elif i < n-1 and ni[i] < l:
            if ni[i]+ni[i+1] >= l:
                cont += 1
                i += 2
            else:
                i += 1
        else:
            i += 1
    return cont

t = int(input())
for _ in range(t):
    n, l, r = map(int, input().split())
    ni = list(map(int, input().split()))
    print(solve(n, l, r, ni))
