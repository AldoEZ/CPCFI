def solve(prefix, op, m, n):
    for j in range(m):
        for i in range(n):
            if prefix[i] <= op[j][2] and prefix[i] >= op[j][1]:
                if op[j][0] == '+':
                    prefix[i] += 1
                elif op[j][0] == '-':
                    prefix[i] -= 1
        print(max(prefix), end=" ")
    print()

t = int(input())
for _ in range(t):
    op = []
    n, m = map(int, input().split())
    prefix = list(map(int, input().split()))
    for i in range(m):
        op.append(list(input().split()))
        op[i][1] = int(op[i][1])
        op[i][2] = int(op[i][2])
    solve(prefix, op, m, n)