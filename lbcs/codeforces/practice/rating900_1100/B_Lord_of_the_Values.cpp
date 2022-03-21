#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll *arr = new ll[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<vector<int>> ans;
        for (int j = n - 1; j >= 0; j--)
        {
            int i = j - 1;
            int cnt = 0, cnt1 = 0;
            int index1 = j, index2 = j;
            while (i >= 0)
            {
                if (max(arr[j], arr[i]) % min(arr[j], arr[i]) == 0)
                {
                    if (arr[i] >= arr[j])
                    {
                        if (arr[i] == arr[j])
                        {
                            cnt = arr[i] / arr[j];
                            cnt += cnt;
                            index1 = i;
                        }
                        else if ((2 * arr[i]) == (arr[j]))
                        {
                            cnt = arr[i] / arr[j];
                            index1 = i;
                        }
                    }
                    else
                    {
                        cnt = arr[j] / arr[i];
                        cnt += cnt;
                        index1 = i;
                    }
                }
                i--;
            }
            i = j + 1;
            while (i < n)
            {
                ll temp = abs(arr[i]);
                if (max(temp, arr[i]) % min(temp, arr[i]) == 0)
                {
                    if (arr[j] <= temp)
                    {
                        if (arr[j] == temp)
                        {
                            cnt1 = temp / arr[j];
                            cnt1 += cnt1;
                            index2 = i;
                        }
                        else if (arr[j] == (2 * temp))
                        {
                            cnt1 = temp / arr[j];
                            index2 = i;
                        }
                    }
                    else
                    {
                        cnt1 = arr[j] / temp;
                        cnt1 += cnt1;
                        index2 = i;
                    }
                }
                i++;
            }
            if (cnt < cnt1)
            {
                while (cnt != 0)
                {
                    ans.push_back({2, index1 + 1, j + 1});

                    cnt--;
                }
            }
            else
            {
                while (cnt1 != 0)
                {
                    ans.push_back({1, j + 1, index2 + 1});
                    // cout << 1 << " " << j << " " << index2 << endl;
                    cnt1--;
                }
            }
            arr[j] = (-arr[j]);
        }
        cout << ans.size() << endl;
        for (auto itr : ans)
        {
            for (auto it : itr)
            {
                cout << it << " ";
            }
            cout << endl;
        }
    }
    return 0;
}