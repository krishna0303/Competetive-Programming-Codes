#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        map<int, int> m;
        map<int, pair<int, int>> ma;

        for (int i = 0; i < n; i++)
        {
            m[arr[i]] += 1;
        }
        for (auto it : m)
        {
            // cout << it.first << " " << it.second << endl;
            ma[it.first] = make_pair(it.second, 1);
        }
        int *ans = new int[n];
        for (int i = 0; i < n; i++)
        {
            ans[i] = 0;
        }

        int color = 1;

        for (int i = 0; i < n; i++)
        {

            if (ma[arr[i]].first <= k - 1)
            {
                ans[i] = color;
                // ma[arr[i]].first -= 1;
                color += 1;
                if (color > k)
                {
                    color = 1;
                }
            }
            else
            {
                if ((ma[arr[i]].first >= k) && (ma[arr[i]].second <= k))
                {
                    ans[i] = ma[arr[i]].second;
                    // ma[arr[i]].first -= 1;
                    ma[arr[i]].second += 1;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}