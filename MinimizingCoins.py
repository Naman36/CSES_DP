m = float("inf")


def getCoins(arr, n, x, dp):
    for i in range(2, n + 1):
        for j in range(1, x + 1):
            if j - arr[i - 1] >= 0:
                dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - arr[i - 1]])
            else:
                dp[i][j] = dp[i - 1][j]
    return dp[n][x]


n, x = map(int, input().split())
arr = [int(x) for x in input().split()]
dp = [[0 for _ in range(x + 1)] for _ in range(n + 1)]

for i in range(x + 1):
    dp[0][i] = m
for i in range(1, x + 1):
    if i % arr[0] == 0:
        dp[1][i] = i // arr[0]
    else:
        dp[1][i] = m
ans = getCoins(arr, n, x, dp)
if ans == m:
    print(-1)
else:
    print(ans)
