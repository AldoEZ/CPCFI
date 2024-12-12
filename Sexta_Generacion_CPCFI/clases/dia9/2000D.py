# codeforces
def solve(n, points, s):
    prefix = [0]
    resp = 0
    i, pos = 0, 0
    maxim, suma = 0, 0
    for i in range(n):
        prefix.append(prefix[i] + points[i])
    while True:
        if i == n:
            i = 0
        if s[i] == 'L':
            pos = i
            i += 1
        if s[i] == 'R' and pos < i:
            suma = prefix[i+1] - prefix[pos-1]
        
        if suma > maxim:
            maxim = suma
            s[i], s[pos] = '.', '.'
            resp += maxim
        i += 1
    return resp

t = int(input())
for _ in range(t):
    n = int(input())
    points = list(map(int, input().split()))
    s = list(input())
    print(solve(n, points, s))