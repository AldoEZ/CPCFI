def solve(n, ni):
    dia = 0
    for concursos in ni:
        if concursos >= dia+1:
            dia += 1
    return dia

n = int(input())
ni = list(map(int, input().split()))
ni.sort()
print(solve(n, ni))
