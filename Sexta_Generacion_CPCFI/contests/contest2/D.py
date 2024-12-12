def solve(n, p, q):
    pq = set(p+q)
    for i in range(1, n+1):
        if i not in pq:
            print("Oh, my keyboard!")
            return
    print("I become the guy.")

n = int(input())
p = list(map(int, input().split()))
q = list(map(int, input().split()))
p = p[1:]
q = q[1:]
solve(n, p, q)
