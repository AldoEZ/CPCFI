def cadena(cadena,k):
    if k == 1: return "2"
    
    if k%2 == 0:
        cadenas = "(" + cadena(cadena/2, k) + ")^2"
    else:
        cadenas = "(2*" + cadena(cadena-1, k) + ")"
        
    return cadenas

t = int(input())
for _ in range(t):
    k = int(input())
    print(cadena("",k))
