def solve(n, ni, m, mi):
    pass

n = int(input())
ni = list(map(int, input().split()))
m = int(input())
mi = list(map(int, input().split()))


prefix = [0]
for i in range(n):
    prefix.append(prefix[i] + ni[i])
print(prefix)

for i in range(m):
    print(solve(n, ni, mi[i]))
