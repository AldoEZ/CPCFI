def solve(n, s):
    aux = ""
    max = 0
    resp = ""
    for i in range(0, len(s)-1):
        aux = s[i]+s[i+1]
        u = conicidencias(aux, s)
        if max < u:
            max = u
            resp = aux
    return resp


def conicidencias(aux, s):
    cont = 0
    for i in range(0, len(s)-1):
        if s[i]+s[i+1] == aux:
            cont += 1
    return cont

n = int(input())
s = list(input().upper())
print(solve(n, s))
