#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m = 1e9 + 7;
    int n, x;
    cin >> n >> x;
    int coin[n];
    for (int i = 0; i < n; i++)
    {
        cin >> coin[i];
    }
    int dp[n + 1][x + 1];
    for (int i = 0; i <= x; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            if (j - coin[i - 1] >= 0)
            {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - coin[i - 1]]) % m;
            }
            else
            {
                dp[i][j] = dp[i - 1][j] % m;
            }
        }
    }
    cout << dp[n][x] << endl;
}