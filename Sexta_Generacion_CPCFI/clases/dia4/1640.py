# cses
def solve(n, x, ni):
    if x <= 1:
        print("IMPOSSIBLE") 
    dif = 0
    resp = []
    for i in range(n-1):
        if ni[i] >= x:
            continue
        dif = x - ni[i]
        if dif in ni[i+1:]:
            resp.append(i+1)
            ni = ni[i+1:]
            resp.append((ni.index(dif))+1)
            print(*resp)
            return
    print("IMPOSSIBLE") 

n, x = map(int, input().split())
ni = list(map(int, input().split()))
ni.sort()
solve(n,x,ni)
