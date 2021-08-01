#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k, n, m;
        cin >> k >> n >> m;
        int arr1[n], arr2[m];
        for (int i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> arr2[i];
        }
        vector<int> ans;
        int i = 0;
        int j = 0;
        bool flag = true;
        while (i < n && j < m)
        {
            if (arr1[i] == 0)
            {
                ans.push_back(arr1[i]);
                k++;
                i++;
            }
            else if (arr2[j] == 0)
            {
                ans.push_back(arr2[j]);
                k++;
                j++;
            }
            else if (arr1[i] <= k)
            {
                ans.push_back(arr1[i]);
                i++;
            }
            else if (arr2[j] <= k)
            {
                ans.push_back(arr2[j]);
                j++;
            }
            else
            {
                flag = false;
                break;
            }
        }
        while (i < n)
        {
            if (arr1[i] == 0)
            {
                ans.push_back(arr1[i]);
                i++;
                k++;
            }
            else if (arr1[i] <= k)
            {
                ans.push_back(arr1[i]);
                i++;
            }
            else
            {
                flag = false;
                break;
            }
        }
        while (j < m)
        {
            if (arr2[j] == 0)
            {
                ans.push_back(arr2[j]);
                j++;
                k++;
            }
            else if (arr2[j] <= k)
            {
                ans.push_back(arr2[j]);
                j++;
            }
            else
            {
                flag = false;
                break;
            }
        }
        if (!flag)
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