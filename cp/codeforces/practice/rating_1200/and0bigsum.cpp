#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;

ll fact(ll n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return ((n % mod) * fact(n - 1) % mod) % mod;
    }
}

ll power(ll x, ll k)
{
    ll ans = 1;
    for (int i = 0; i < k; i++)
    {
        ans = ((ans % mod) * (x % mod)) % mod;
    }

    // cout << ans << endl;
    return ans % mod;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll count = power(2, k - 1);
        ll factorial = fact(n);
        // cout << factorial << endl;
        ll ans = ((count % mod) * (factorial % mod)) % mod;
        cout << ans % mod << endl;
    }
    return 0;
}