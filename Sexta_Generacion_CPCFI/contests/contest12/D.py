def solve(n,m,a):
    sa1 = list("B"*m)
    sa2 = list("B"*m)
    
    for ai in a:
        op = (m+1-ai)
        
        sa1[ai-1] = 'A'
        if op <= m:
            sa2[op-1] = 'A'
        
        if sa1 < sa2:
            sa2 = sa1.copy()
        elif sa2 < sa1:
            sa1 = sa2.copy()
    
    s = min(sa1,sa2)
    for el in s:
        print(el,end="")
    print()

t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    solve(n,m,a)
