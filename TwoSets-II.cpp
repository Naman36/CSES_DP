#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(i, j, k) for (ll i = j; i < k; i++)

int main()
{
    int n;
    int mod = 1e9 + 7;
    cin >> n;
    ll s = n * (n + 1) / 2;
    vector<vector<ll>> dp(n, vector<ll>(s + 1, 0));
    if (s % 2 == 0)
    {
        s = s / 2;

        dp[0][0] = 1;

        loop(i, 1, n)
        {
            loop(j, 0, s + 1)
            {
                if (j - i >= 0)
                {
                    dp[i][j] = dp[i - 1][j] % mod + dp[i - 1][j - i] % mod;
                    dp[i][j] %= mod;
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] % mod;
                    dp[i][j] %= mod;
                }
            }
        }
        cout << (dp[n - 1][s] % mod);
    }
    else
    {
        cout << 0;
    }
}