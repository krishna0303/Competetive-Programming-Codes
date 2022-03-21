#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, m;
        cin >> k >> n >> m;
        int *arr1 = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }
        int *arr2 = new int[m];
        for (int i = 0; i < m; i++)
        {
            cin >> arr2[i];
        }
        int i = 0, j = 0;
        vector<int> ans;
        bool flag = false;
        while (i < n && j < m)
        {
            if (arr1[i] == 0)
            {
                ans.push_back(arr1[i]);
                i += 1;
                k += 1;
            }
            else if (arr2[j] == 0)
            {
                ans.push_back(arr2[j]);
                j += 1;
                k += 1;
            }
            else
            {
                if (arr1[i] < arr2[j])
                {
                    if (arr1[i] <= k)
                    {
                        ans.push_back(arr1[i]);
                        i += 1;
                    }
                    else
                    {
                        flag = true;
                        break;
                    }
                }
                else
                {
                    if (arr2[j] <= k)
                    {
                        ans.push_back(arr2[j]);
                        j += 1;
                    }
                    else
                    {
                        flag = true;
                        break;
                    }
                }
            }
        }
        while (i < n)
        {
            if (arr1[i] == 0)
            {
                ans.push_back(arr1[i]);
                k += 1;
                i += 1;
            }
            else if (arr1[i] <= k)
            {
                ans.push_back(arr1[i]);
                i += 1;
            }
            else
            {
                flag = true;
                break;
            }
        }
        while (j < m)
        {
            if (arr2[j] == 0)
            {
                ans.push_back(arr2[j]);
                k += 1;
                j += 1;
            }
            else if (arr2[j] <= k)
            {
                ans.push_back(arr2[j]);
                j += 1;
            }
            else
            {
                flag = true;
                break;
            }
        }
        if (flag)
        {
            cout << -1 << endl;
        }
        else
        {
            for (int i = 0; i < ans.size(); i++)
            {
                cout << ans[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}