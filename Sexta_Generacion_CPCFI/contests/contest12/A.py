def solve(ni):
    if ni == sorted(ni):
        return 0
    pos = ni.index(min(ni))
    
    nia = ni[pos+1:]
    
    if nia != sorted(nia):
        return -1
    else:
        return len(ni[:pos])

t = int(input())
for _ in range(t):
    n = int(input())
    ni = list(map(int, input().split()))
    print(solve(ni))
