#include <bits/stdc++.h>
using namespace std;

//for better understanding of this solution watch https://www.youtube.com/watch?v=abCbx8dtYqU
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        map<int, int> ma;
        for (int i = 0; i < n; i++)
        {
            ma[(arr[i] % m)] += 1;
        }
        int ans = 0;
        for (auto it : ma)
        {
            // cout << it.first << " " << it.second << endl;
            if (it.first == 0 && &it.second != 0)
            {
                // cout << ma[m - it.first] << endl;
                ans += 1;
            }
            else if (m % 2 == 0 && it.first == (m / 2) && it.second != 0)
            {
                // cout << ma[m - it.first] << endl;
                ans += 1;
            }
            else
            {
                // cout << ma[m - it.first] << endl;
                if (it.second != 0)
                {

                    if (ma[m - it.first] != 0)
                    {
                        if ((it.second == ma[m - it.first]) || abs(it.second - ma[m - it.first]) == 1)
                        {
                            ans += 1;
                        }
                        else
                        {
                            int minm = min(it.second, ma[m - it.first]);
                            int maxm = max(it.second, ma[m - it.first]);
                            ans += 1;
                            ans += (maxm - (minm + 1));
                        }
                        ma[m - it.first] = 0;
                        it.second = 0;
                    }
                    else
                    {
                        ans += it.second;
                        ma[m - it.first] = 0;
                        it.second = 0;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}