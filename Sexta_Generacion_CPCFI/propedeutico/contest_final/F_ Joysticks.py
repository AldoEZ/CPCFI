def solve(a1, a2, cont):
    if a1 <= 1 or a2 <= 1:
        return 0        
    elif (a1 == 2 and a2 == 2) or (a1 == 2 and a2 < 2) or (a2 == 2 and a1 < 2):
        return 1
    elif a1 >= a2:
        while a1 > 2:
            a1 -= 2
            a2 += 1
            cont += 1
        return cont + solve(a1, a2, 0)
    elif a2 > a1:
        while a2 > 2:
            a2 -= 2
            a1 += 1
            cont += 1
        return cont + solve(a1, a2, 0)

a1, a2 = map(int, input().split())
print(max(a1+a2-3+((a2-a1)%3>0),0))
