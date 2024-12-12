def mov(fichas):
    ficha_inicial = fichas.index(1)
    ficha_final = len(fichas) - 1 - fichas[::-1].index(1)
    movs = 0

    for f in range(ficha_inicial,ficha_final+1):
        if fichas[f] == 0:
            movs += 1
    return movs

t = int(input())
for _ in range(t):
    n = input()
    fichas = list(map(int, input().split()))
    print(mov(fichas))
