# cses
def solve(n,x,ci):
    dp = [float('inf')] * (x+1)
    dp[0] = 0
    
    for i in range(1, x+1):
        for j in range(n):
            if (ci[j] > i) or  (dp[i-ci[j]] == float('inf')):
                continue
            dp[i] = min(dp[i], dp[i-ci[j]] + 1)
    
    if dp[x] != float('inf'):
        return dp[x]
    else:
        return -1

n, x = map(int, input().split())
ci = list(map(int, input().split()))
print(solve(n,x,ci))
