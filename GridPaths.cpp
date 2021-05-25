#include <bits/stdc++.h>
using namespace std;

int main()
{
    int mod = 1e9 + 7;
    int n;
    cin >> n;
    char grid[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    long long dp[n][n];
    dp[0][0] = 1;
    if (grid[0][0] == '*')
    {
        cout << 0;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != 0 or j != 0)
                {
                    if (grid[i][j] == '*')
                    {
                        dp[i][j] = 0;
                    }
                    else
                    {
                        dp[i][j] = 0;
                        if (i - 1 >= 0)
                        {
                            dp[i][j] += dp[i - 1][j] % mod;
                        }
                        if (j - 1 >= 0)
                        {
                            dp[i][j] += dp[i][j - 1] % mod;
                        }
                    }
                }
            }
        }
        cout << dp[n - 1][n - 1] % mod;
    }
}