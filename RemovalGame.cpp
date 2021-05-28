#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(i, j, k) for (ll i = j; i < k; i++)
int main()
{
    int n;
    cin >> n;
    ll arr[n];
    loop(i, 0, n) cin >> arr[i];
    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    loop(len, 1, n + 1)
    {
        for (ll i = 0; i <= n - len; i++)
        {
            ll j = i + len - 1;
            ll x, y, z;
            x = (i + 2 <= j) ? dp[i + 2][j] : 0;
            y = (i + 1 <= j - 1) ? dp[i + 1][j - 1] : 0;
            z = (i <= j - 2) ? dp[i][j - 2] : 0;
            dp[i][j] = max(min(x, y) + arr[i], min(y, z) + arr[j]);
        }
    }
    cout << dp[0][n - 1];
}