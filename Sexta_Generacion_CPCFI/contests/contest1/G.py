def solve(s):
    if 'A' not in s:
        return 0
    max = 0
    cont = 0
    s = s[s.index('A')+1:]
    for i in range(len(s)):
        if s[i] == 'A':
            cont = 0
            continue
        cont += 1
        if cont > max:
            max = cont
    return max

t = int(input())
for _ in range(t):
    k = int(input())
    s = input()
    print(solve(s))
