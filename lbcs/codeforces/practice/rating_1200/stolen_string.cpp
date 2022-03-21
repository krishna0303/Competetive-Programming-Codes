#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string s[2 * n - 1];
        for (int i = 0; i < (2 * n - 1); i++)
        {
            cin >> s[i];
        }
        string ans;
        for (int i = 0; i < m; i++)
        {
            map<char, pair<int, int>> m1;
            for (int j = 0; j < (2 * n - 1); j++)
            {
                if (m1[s[j][i]].first)
                {
                    m1[s[j][i]] = make_pair(m1[s[j][i]].first + 1, j);
                }
                else
                {
                    m1[s[j][i]] = make_pair(1, j);
                }
            }
            bool flag = false;
            for (auto it : m1)
            {
                if (it.second.first == 1)
                {
                    ans = s[it.second.second];
                    flag = true;
                    break;
                }
            }

            if (i == m - 1)
            {
                for (auto it : m1)
                {
                    if (it.second.first % 2 != 0)
                    {
                        ans = s[it.second.second];
                        flag = true;
                        break;
                    }
                }
            }
            if (flag)
            {
                break;
            }
        }

        cout << ans << endl;
        cout.flush();
    }
    return 0;
}