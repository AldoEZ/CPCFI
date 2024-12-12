def solve(n, m, ci, ti):
    c, t = 0, 0
    r = []
    while c < n and t < m:
        r.append(abs(ci[c]-ti[t]))
        if ci[c] < ti[t]:
            c += 1
        elif ti[t] < ci[c] and ((abs(ti[t] - ci[c])) <= r[-1]):
            c += 1
            t += 1
        else:
            t += 1
    while c < n:
        r.append(abs(ci[c]-ti[t-1]))
        c += 1
    while t < m:
        r.append(abs(ci[c-1]-ti[t]))
        t += 1
    return max(r)

n, m = map(int, input().split())
ci = list(map(int, input().split()))
ti = list(map(int, input().split()))
ci.sort()
ti.sort()
print(solve(n, m, ci, ti))
