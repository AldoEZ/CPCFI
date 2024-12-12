def solve():
    pass

t = int(input())
for _ in range(t):
    i, j = map(int, input().split())
    s = []
    for i in range(i, j + 1):
        if i % 2 == 0 or i % 3 == 0 or i % 5 == 0 or i % 7 == 0 or i % 11 == 0:
            continue
        s.append(i)

    print(len(s))
