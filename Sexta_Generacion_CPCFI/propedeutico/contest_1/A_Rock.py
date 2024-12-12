def rock(pos):
    columna_actual, fila_actual = pos
    posiciones = []

    for f in range(1,9):
        if str(f) != fila_actual:
            posiciones.append(columna_actual + str(f))
    
    for c in 'abcdefgh':
        if c != columna_actual:
            posiciones.append(c + fila_actual)
    
    return posiciones

t = int(input())
for _ in range(t):
    pos = input()
    posiciones = rock(pos)
    print("".join(posiciones))
