# cses
MOD = 1000000007
TAM = 1000000

n = int(input())
dp = [0 for _ in range(TAM+1)]
dp[0],dp[1],dp[2],dp[3],dp[4],dp[5],dp[6] = 1,1,2,4,8,16,32

for i in range(7,n+1):
    for j in range(1,7):
        dp[i] += dp[i-j]
        dp[i] %= MOD
print(dp[n])
