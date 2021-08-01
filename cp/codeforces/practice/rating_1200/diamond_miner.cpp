#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
bool compare1(const pair<ll, ll> &a, const pair<ll, ll> &b)
{
    return abs(a.first) < abs(b.first);
}
bool compare2(const pair<ll, ll> &a, const pair<ll, ll> &b)
{
    return abs(a.second) < abs(b.second);
}

//best problem for handle datatypes and trheir precision
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<pair<ll, ll>> v1, v2;
        for (int i = 0; i < 2 * n; i++)
        {
            ll x, y;
            cin >> x >> y;
            if (x == 0 && y != 0)
            {
                v2.push_back({x, abs(y)});
            }
            else if (x != 0 && y == 0)
            {
                v1.push_back({abs(x), y});
            }
        }

        sort(v1.begin(), v1.end(), compare1);
        sort(v2.begin(), v2.end(), compare2);
        double ans = 0.0;
        for (int i = 0; i < n; i++)
        {
            ll ans1 = (v1[i].first * v1[i].first);
            ll ans2 = (v2[i].second * v2[i].second);
            ans += sqrt(ans1 + ans2);
        }
        cout.precision(17);
        cout << ans << endl;
    }
    return 0;
}