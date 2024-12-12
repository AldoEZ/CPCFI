def solve(n,s):
    aux = []
    for i in range(n):
        if s[i] in aux:
            s1 = set(s[:i])
            s2 = set(s[i:])
            return len(s1) + len(s2)
        else:
            aux.append(s[i])

t = int(input())
for _ in range(t):
    n = int(input())
    s = list(input())
    print(solve(n,s))
