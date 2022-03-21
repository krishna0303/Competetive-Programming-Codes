#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {

        ll a, b;
        cin >> a >> b;
        if (a == b)
        {
            cout << 0 << " " << 0 << endl;
        }
        
        else
        {
            ll maxm = abs(a - b);
            ll rem = max(a, b) % maxm;
            ll ans = min(maxm - rem,rem);
            if (rem == 0)
            {
                ans = 0;
            }

            cout << maxm << " " << ans << endl;
        }
    }
    return 0;
}