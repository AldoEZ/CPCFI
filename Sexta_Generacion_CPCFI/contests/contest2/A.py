def solve(ni):
    par = []
    impar = []
    for i in range(1, len(ni)+1):
        if i%2 == 0:
            par.append(ni[i-1])
        else:
            impar.append(ni[i-1])
    dif = max(sum(par), sum(impar)) - min(sum(par), sum(impar))
    

t = int(input())
for _ in range(t):
    n = int(input())
    ni = list(map(int, input().split()))
    solve(ni)
