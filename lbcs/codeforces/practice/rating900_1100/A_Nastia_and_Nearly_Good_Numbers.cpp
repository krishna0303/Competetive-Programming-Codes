#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        if (b == 1)
        {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        ll x = (a * (b + 1));
        ll y = (a * (b - 1));
        ll z = (2 * a * b);

        cout << x << " " << y << " " << z << endl;
    }
    return 0;
}