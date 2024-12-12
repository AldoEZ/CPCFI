def solve(ni, c):
    ni.sort()
    cont = 0
    for i in range(1, max(ni) + 1):
        try:
            aux_1 = ni.index(i)
            aux_2 = len(ni) - 1 - ni[::-1].index(i)
            cont += min(c, contOrbit(ni[aux_1:aux_2+1]))
        except:
            continue
    return cont

def contOrbit(aux):
    return len(aux)      

t = int(input())
for _ in range(t):
    n, c = map(int, input().split())
    ni = list(map(int, input().split()))
    print(solve(ni, c))
