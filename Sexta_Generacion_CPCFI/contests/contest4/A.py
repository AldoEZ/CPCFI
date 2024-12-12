def solve(a):
    i = 0
    while ('b' in a) or ('B' in a):
        if a[i] == 'b':
            a.pop(i)
            b = a[:a.index('b')]
            buscarMin(a, b)
        elif a[i] == 'B':
            a.pop(i)
            b = a[:a.index('b')]
            buscarMay(a, b)


def buscarMin(a, b):
    indice = 0
    for i in range(len(b)):
        if b[i] == b[i].lower():
            indice = i
    a.pop(indice)

def buscarMay(a, b):
    indice = 0
    for i in range(len(b)):
        if b[i] == b[i].upper():
            indice = i
    a.pop(indice)

t = int(input())
for _ in range(t):
    a = input()
    a = list(a)
    solve(a)
