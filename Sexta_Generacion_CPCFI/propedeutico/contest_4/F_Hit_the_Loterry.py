def solve(n, cambio):
    cont = 0
    while n > 0:
        if n >= cambio[0]:
            billetes = n // cambio[0]
            n %= cambio[0]
            cont += billetes
        cambio = cambio[1:]
    return cont

cambio = [100,20,10,5,1]
n = int(input())
print(solve(n, cambio))
