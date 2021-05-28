#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(i, j, k) for (ll i = j; i < k; i++)
#define mid(l, r) (l + (r - l) / 2)

struct Job
{
    ll s, f, p;
};

bool cmp(Job a, Job b)
{
    return a.f < b.f;
}
ll binarySearch(Job arr[], int i)
{
    ll lo = 0;
    ll hi = i - 1;
    while (lo <= hi)
    {
        ll m = mid(lo, hi);
        if (arr[m].f < arr[i].s)
        {
            if (arr[m + 1].f < arr[i].s)
            {
                lo = m + 1;
            }
            else
            {
                return m;
            }
        }
        else
        {
            hi = m - 1;
        }
    }
    return -1;
}

int main()
{
    ll n;
    cin >> n;
    Job arr[n];
    loop(i, 0, n)
    {
        cin >> arr[i].s >> arr[i].f >> arr[i].p;
    }
    vector<ll> dp(n, 0);

    sort(arr, arr + n, cmp);
    dp[0] = arr[0].p;
    loop(i, 1, n)
    {
        ll incl = arr[i].p;
        ll idx = binarySearch(arr, i);
        if (idx != -1)
        {
            incl += dp[idx];
        }
        ll excl = dp[i - 1];
        dp[i] = max(incl, excl);
    }
    cout << dp[n - 1];
}