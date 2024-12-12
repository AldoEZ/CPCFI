def gcd(x,y):
    if x == y:
        return x
    else:
        return 1
x, y = map(int,input().split())
print(gcd(x,y))
