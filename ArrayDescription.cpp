#include <bits/stdc++.h>
using namespace std;

int main()
{
    int mod = 1e9 + 7;
    int n, m;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<vector<long long>> dp(m + 1, vector<long long>(n, 0));

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            if (arr[i] == 0)
            {
                for (int j = 1; j <= m; j++)
                {
                    dp[j][i] = 1;
                }
            }
            else
                dp[arr[i]][i] = 1;
            continue;
        }

        if (arr[i] != 0)
        {
            dp[arr[i]][i] += ((dp[arr[i] - 1][i - 1]) % mod) + (dp[arr[i]][i - 1] % mod) + ((arr[i] + 1 <= m) ? dp[arr[i] + 1][i - 1] % mod : 0);
            // cout << dp[arr[i] - 1][i - 1]  << "," << dp[arr[i]][i - 1]<<dp[arr[i] + 1][i - 1] << endl;
            // cout << dp[arr[i]][i] << endl;
        }
        else
        {
            for (int j = 1; j <= m; j++)
            {
                dp[j][i] = dp[j][i - 1];
                dp[j][i] = dp[j][i] % mod + dp[j - 1][i - 1] % mod;
                if (j < m)
                {
                    dp[j][i] = dp[j][i] % mod + dp[j + 1][i - 1] % mod;
                }
                dp[j][i] %= mod;
                // cout << dp[j][i] << endl;
            }
        }
    }

    long long ans = 0;
    if (arr[n - 1] != 0)
    {
        cout << dp[arr[n - 1]][n - 1] % mod;
    }
    else
    {
        for (int i = 1; i <= m; i++)
        {
            ans += dp[i][n - 1] % mod;
            ans %= mod;
        }
        cout << ans;
    }
}

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//   int mod = 1e9+7;
//   int n, m;
//   cin >> n >> m;
//   vector<vector<int>> dp(n,vector<int>(m+1,0));
//   int x0;
//   cin >> x0;
//   if (x0 == 0) {
//     fill(dp[0].begin(), dp[0].end(), 1);
//   } else {
//     dp[0][x0] = 1;
//   }
//   for (int i = 1; i < n; i++) {
//     int x;
//     cin >> x;
//     if (x == 0) {
//       for (int j = 1; j <= m; j++) {
// 	for (int k : {j-1,j,j+1}) {
// 	  if (k >= 1 && k <= m) {
// 	    (dp[i][j] += dp[i-1][k]) %= mod;
// 	  }
// 	}
//       }
//     } else {
//       for (int k : {x-1,x,x+1}) {
// 	if (k >= 1 && k <= m) {
// 	  (dp[i][x] += dp[i-1][k]) %= mod;
// 	}
//       }
//     }
//   }
//   int ans = 0;
//   for (int j = 1; j <= m; j++) {
//     (ans += dp[n-1][j]) %= mod;
//   }
//   cout << ans << endl;
// }