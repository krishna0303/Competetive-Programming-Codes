#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define maxima 1000000000000000000
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll *arr = new ll[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        // bool flag = false;
        // for (int i = 1; i < n; i++)
        // {
        //     if (arr[i - 1] > arr[i])
        //     {
        //         flag = true;
        //     }
        // }
        // if (!flag)
        // {
        //     cout << 0 << endl;
        //     continue;
        // }
        // cout << n - 1 << endl;

        vector<vector<ll>> ans;
        for (int i = n - 1; i > 0; i--)
        {
            ll maxm = -maxima;
            ll index = -1;
            for (int j = 0; j <= i; j++)
            {
                if (maxm < arr[j])
                {
                    maxm = arr[j];
                    index = j;
                }
            }
            if (index == i)
            {

                continue;
            }
            else
            {
                ll *arr1 = new ll[n];
                for (int j = 0; j <= i; j++)
                {
                    arr1[j] = arr[(j + index + 1) % (i + 1)];
                }
                arr = arr1;

                ans.push_back({1, i + 1, index + 1});
            }
        }
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}