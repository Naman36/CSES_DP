# def diceRec(n):
#     if n < 0:
#         return 0
#     if n == 0:
#         return 1
#     return diceRec(n - 6) + diceRec(n - 5) + diceRec(n - 4) + diceRec(n - 3) + diceRec(n - 2) + diceRec(n - 1)


def dice(n, dp):
    if n < 7:
        return dp[n]
    for i in range(7, n + 1):
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4] + dp[i - 5] + dp[i - 6]
    return dp[n]


n = int(input())
dp = [0] * (n + 1)

if n >= 7:
    for i in range(1, 7):
        dp[i] = 2 ** (i - 1)

    ans = dice(n, dp)
else:
    ans = 2 ** (n - 1)

print(ans % (10 ** 9 + 7))

