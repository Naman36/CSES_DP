#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        x += arr[i];
    }
    vector<vector<bool>> dp(n + 1, vector<bool>(x + 1, false));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }
    dp[1][arr[0]] = true;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            if (j - arr[i - 1] >= 0)
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    vector<int> p;
    for (int i = 1; i <= x; i++)
    {
        if (dp[n][i] == true)
        {
            p.push_back(i);
        }
    }
    cout << p.size() << endl;
    for (int v : p)
    {
        cout << v << ' ';
    }
    cout << endl;
}
