#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n, q, k;
    cin >> n >> q >> k;
    ll *arr = new ll[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll *dp = new ll[n];
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            dp[i] = (arr[i + 1] - arr[i]) - 1;
        }
        else if (i == n - 1)
        {
            dp[i] = (arr[i] - arr[i - 1]) - 1;
        }
        else
        {
            dp[i] = (arr[i + 1] - arr[i] - 1) + (arr[i] - arr[i - 1] - 1);
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
    // cout << dp[0] << " ";
    for (int i = 1; i < n; i++)
    {

        dp[i] += dp[i - 1];
        // cout << dp[i] << " ";
    }
    // cout << endl;

    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        l--;
        r--;
        if (l == r)
        {
            cout << k - 1 << endl;
        }
        else
        {
            ll ans = 0;
            ans += (arr[l] - 1) + arr[l + 1] - arr[l] - 1;
            ans += (k - arr[r]) + arr[r] - arr[r - 1] - 1;
            ans += (dp[r - 1] - dp[l]);
            cout << ans << endl;
        }
    }

    return 0;
}