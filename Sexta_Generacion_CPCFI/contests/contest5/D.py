def solve(n,k,a,b):
    pass

t = int(input())
for _ in range(t):
    list = []
    n, r, avg = map(int, input().split())
    for i in range(n):
        aux = list(map(int, input().split()))
        list.append(aux)
    print(list)
