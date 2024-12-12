def solve(n, ni):
    resp = []
    for a in range(0, n):
        if ni[a] == a+1:
            resp.append(ni[a])
            continue
        aux = [0 for _ in range(n)]
        i = a
        while 2 not in aux:
            aux[i] += 1
            i = ni[i]-1
        resp.append(aux.index(max(aux))+1)
    return resp

n = int(input())
ni = list(map(int, input().split()))
for num in solve(n, ni):
    print(num, end=" ")
