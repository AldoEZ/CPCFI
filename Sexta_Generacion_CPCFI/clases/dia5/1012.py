# usaco
def solve(n, a, b):
    ban = True
    for i in range(n):
        if ban is False:
            ban = True

n = int(input())
a = input()
b = input()
print(solve(n, a, b))
