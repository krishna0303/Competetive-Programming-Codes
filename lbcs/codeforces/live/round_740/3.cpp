#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> dist;
        for (int i = 0; i < n; i++)
        {
            int cave;
            cin >> cave;
            int High = 0;
            for (int j = 0; j < cave; j++)
            {
                int monster;
                cin >> monster;
                High = max(High, monster - (j - 1));
            }
            dist.push_back(make_pair(High, cave));
        }
        sort(dist.begin(), dist.end());

        int Ans = 0;
        int temp = 0;
        temp = dist[0].first;
        Ans = temp;
        for (int i = 0; i < n; i++)
        {
            //
            if (temp < dist[i].first)
            {
                Ans += (dist[i].first - temp);
                temp == dist[i].first;
            }
            temp += dist[i].second;
        }
        cout << Ans << endl;
    }

    return 0;
}