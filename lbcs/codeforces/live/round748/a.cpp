#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        ll a, b, c;
        cin >> a >> b >> c;

        ll x, y, z;
        if (a > max(b, c))
        {
            x = 0;
        }
        else
        {
            x = (max(b, c) + 1) - a;
        }
        if (b > max(a, c))
        {
            y = 0;
        }
        else
        {
            y = (max(a, c) + 1) - b;
        }
        if (c > max(b, a))
        {
            z = 0;
        }
        else
        {
            z = (max(b, a) + 1) - c;
        }
        cout << x << " " << y << " " << z << endl;
    }
    return 0;
}