#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<pair<int, int>> v;
        for (int i = 0; i < 3; i++)
        {
            int a, b;
            cin >> a >> b;
            v.push_back({a, b});
        }
        int ans = 0;

        if ((v[0].first == v[1].first && v[1].first == v[2].first))
        {
            if (max(v[0].second, v[1].second) >= v[2].second && v[2].second >= min(v[0].second, v[1].second))
            {
                ans = (max(v[0].second, v[1].second) - min(v[0].second, v[1].second)) + 2;
            }
            else
            {
                ans = (max(v[0].second, v[1].second) - min(v[0].second, v[1].second));
            }
        }
        else if ((v[0].second == v[1].second && v[1].second == v[2].second))
        {
            if (min(v[0].first, v[1].first) <= v[2].first && v[2].first <= max(v[0].first, v[1].first))
            {
                ans = (max(v[0].first, v[1].first) - min(v[0].first, v[1].first)) + 2;
            }
            else
            {
                ans = (max(v[0].first, v[1].first) - min(v[0].first, v[1].first));
            }
        }
        else if ((v[0].second == v[0].first && v[1].second == v[1].first && v[2].second == v[2].first))
        {
            if (min(v[0].first, v[1].first) <= v[2].first && v[2].first <= max(v[0].first, v[1].first))
            {
                ans = (max(v[0].first, v[1].first) - min(v[0].first, v[1].first)) + 2;
            }
            else
            {
                ans = (max(v[0].first, v[1].first) - min(v[0].first, v[1].first));
            }
        }
        else
        {
            ans = (max(v[0].first, v[1].first) - min(v[0].first, v[1].first)) + abs(v[1].second - v[0].second);
        }
        cout << ans << endl;
    }
    return 0;
}