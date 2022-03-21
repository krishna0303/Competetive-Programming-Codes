#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll *dp = new ll[n];
        // cout << "Krishna" << endl;
        // vector<ll> v;
        // for (int i = 0; i < n; i++)
        // {
        //     if (arr[i] != minm && arr[i] > minm)
        //     {
        //         v.push_back(arr[i] - minm);
        for (int i = 0; i < n; i++)
        {
            cin >> dp[i];
        }
        // cout << "Krishna" << endl;
        ll minm = 0;

        sort(dp, dp + n);

        for (int i = 1; i < n; i++)
        {
            minm = __gcd(minm, dp[i] - dp[i - 1]);
        }
        // cout << "Krishna" << endl;
        // vector<ll> v;
        // for (int i = 0; i < n; i++)
        // {
        //     if (arr[i] != minm && arr[i] > minm)
        //     {
        //         v.push_back(arr[i] - minm);
        //     }
        // }
        // ll temp = -1;
        // cout << temp << endl;

        // if (v.size() > 0)
        // {

        //     sort(v.begin(), v.end());
        //     temp = v[0];
        // }

        // bool flag = false;

        // for (int i = 0; i < v.size(); i++)
        // {
        //     if (temp != 0 && v[i] % temp != 0)
        //     {
        //         flag = true;
        //         break;
        //     }
        // }
        if (minm == 0)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << minm << endl;
        }
    }
    return 0;
}