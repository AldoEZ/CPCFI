from math import floor, sqrt

t = int(input())
for _ in range(t):
    n = int(input())
    print(floor(sqrt(n-1)))
