def solve(n):
    if n == 1:
        return 1
    suma = 0
    while n >= 1:
        suma += n
        n //= 2
    return suma

t = int(input())
for i in range(t):
    n = int(input())
    print(solve(n))