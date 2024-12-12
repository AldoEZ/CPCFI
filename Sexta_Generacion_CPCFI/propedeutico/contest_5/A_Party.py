def solve(n, empleados):
    jefes = [[[i+1], 1] for i in range(0, n) if empleados[i] == -1]
    for i in range(n):
        if empleados[i] != -1:
            encontrarPos(empleados[i], jefes)
    maxim = jefes[0][1]
    for i in range(1, len(jefes)):
        if jefes[i][1] > maxim:
            maxim = jefes[i][1]
    return maxim

def encontrarPos(empleado, jefes):
    for i in range(0, len(jefes)):
        if empleado in jefes[i][0]:
            jefes[i][1] += 1
            jefes[i][0].append(empleado)

empleados = list()
n = int(input())
for _ in range(n):
    i = int(input())
    empleados.append(i)
print(solve(n, empleados))
