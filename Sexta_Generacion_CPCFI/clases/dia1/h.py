def solve(n):
    max = 0
    poss = 0
    possf = 0
    cont = 0
    for i in n:
        poss += 1
        if i == "+":
            cont += 1
            if cont >= max:
                max = cont
                possf = poss
        else:
            cont -= 1
    return possf

n = input()
print(solve(n))
