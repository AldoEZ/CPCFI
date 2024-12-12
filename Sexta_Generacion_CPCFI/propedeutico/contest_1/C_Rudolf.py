def ticket(n,m,k,b,c):
    contador = 0
    for moneda in b:
        for mon in c:
            if moneda + mon <= k:
                contador+=1
    return contador

t = int(input())
casos = []

for _ in range(t):
    n, m, k = map(int, input().split())
    b = list(map(int, input().split()))
    c = list(map(int, input().split()))
    caso = ticket(n,m,k,b,c)
    casos.append(caso)

for caso in casos:
    print(caso)
