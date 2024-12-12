def gcd(x,y):
    if y == 0:
        return 1
    return 1+ gcd(y, y%x)

def lcm(x,y):
    return (x*y) / gcd(x,y)

def fac(x):
    if x == 1:
        return x
    return x * fac(x-1)
print(bin(298347))