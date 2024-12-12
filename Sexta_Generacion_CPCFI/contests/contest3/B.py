def solve(n, k, ni):
    while k > 0:
        sub1 = ni[:k]
        sub2 = ni[k:]
        if sub1.reverse() == sub1.sort():
            if sub2.reverse() == sub2.sort():
                subf = sub1+sub2
                ni.sort()
                if ni == subf:
                    print("YES")
                    return
        k -= 1
    print("NO")

t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    ni = list(map(int, input().split()))
    solve(n, k, ni)
