def solve(n, x, ni):
    for num in ni:
        h = num
        aux = llenarLista(ni, h)
        print(aux)

def llenarLista(ni, h):
    aux = list()
    for i in ni:
        if i > h:
            i = h
            aux.append(i)
        aux.append(i)
    return aux

t = int(input())
for _ in range(t):
    n, x = map(int, input().split())
    ni = list(map(int, input().split()))
    ni.sort()
    print(solve(n, x, ni))
