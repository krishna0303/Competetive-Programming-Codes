#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.second / a.first) > (b.second / b.first);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int *arr = new int[n + 1];
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        vector<pair<int, int>> p;

        for (int i = 1; i <= n; i++)
        {
            p.push_back({1, arr[i]});
        }
        sort(p.begin(), p.end(), compare);
        int ans = INT_MIN;
        for (int i = p.size() - 1; i > 0; i--)
        {
            int orr = (p[i].second | p[i - 1].second);

            int temp = (p[i].first * (p[i - 1].first)) - k * orr;
            if (temp > ans)
            {
                ans = temp;
            }
        }
        // for (int i = n; i > 1; i--)
        // {
        //     int orr = (arr[i] | arr[i - 1]);

        //     int temp = (i * (i - 1)) - k * orr;
        //     if (temp > ans)
        //     {
        //         ans = temp;
        //     }
        // }
        cout << ans << endl;
    }
    return 0;
}