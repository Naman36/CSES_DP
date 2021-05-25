n, x = map(int, input().split())

h = [int(x) for x in input().split()]
s = [int(x) for x in input().split()]

dp = [[0 for _ in range(x + 1)] for _ in range(n + 1)]

for i in range(1, n + 1):
    for j in range(1 , x + 1):
        if j - h[i - 1] >= 0:
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - h[i - 1]] + s[i - 1])
        else:
            dp[i][j] = dp[i - 1][j]
print(dp[n][x])