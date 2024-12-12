def cont_balloons(casos_prueba):
    balloons = []
    
    for caso in casos_prueba:
        n, s = caso
        globs = 0
        problemas_resulentos = set()
        
        for problema in s:
            if problema in problemas_resulentos:
                globs += 1
            else:
                globs += 2
                problemas_resulentos.add(problema)
        balloons.append(globs)
        
    return balloons

t = int(input())
casos_prueba = []
for _ in range(t):
    n = int(input())
    s = input().upper()
    casos_prueba.append((n,s))

balloons = cont_balloons(casos_prueba)
for num in balloons:
    print(num)
