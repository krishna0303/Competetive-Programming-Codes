#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int lenf(ll n)
{
    int count = 0;
    while (n != 0)
    {
        count += 1;
        n /= 10;
    }
    return count;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        ll a, b, c;
        cin >> a >> b >> c;
        map<ll, ll> m;
        m[1] = 3;
        m[2] = 11;
        m[3] = 101;
        m[4] = 1009;
        m[5] = 10007;
        m[6] = 100003;
        m[7] = 1000003;
        m[8] = 10000019;
        m[9] = 100030001;
        ll temp = m[c];
        while (a != lenf(temp))
        {
            temp = temp * 2;
        }
        ll x = temp;
        temp = m[c];
        while (b != lenf(temp))
        {
            temp = temp * 3;
        }
        ll y = temp;
        cout << x << " " << y << endl;
    }

    return 0;
}