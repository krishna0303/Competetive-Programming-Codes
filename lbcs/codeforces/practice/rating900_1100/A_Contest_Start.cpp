#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, x, t;
        cin >> n >> x >> t;
        ll rem = t / x;
        ll temp = max(0LL, (n - rem));
        ll ans = 0, small = 0;
        // cout<<temp<<endl;
        temp = temp * rem;

        rem = min(rem, n);
        rem =rem-1;

        small = (rem * (rem + 1)) / 2;

        ans = temp + small;

        cout << ans << endl;
    }
    return 0;
}