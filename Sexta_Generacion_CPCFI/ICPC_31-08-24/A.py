n = int(input())
k = int(input())

aux = k//n

while True:
    if k == n:
        print(1)
        break
    if n == 1:
        print(k)
        break
    if k-(n*aux) < n:
        aux -= 1
    else:
        print(aux)
        break
