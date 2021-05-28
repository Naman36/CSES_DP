#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(i, j, k) for (ll i = j; i < k; i++)

int main()
{
    int n;
    cin >> n;
    ll x;
    vector<ll> dp;
    loop(i, 0, n)
    {
        cin >> x;
        auto it = lower_bound(dp.begin(), dp.end(), x);
        if (it == dp.end())
        {
            dp.push_back(x);
        }
        else
        {
            *it = x;
        }
    }

    cout << dp.size();
}