#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
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
        sort(arr, arr + n);
        int minm = INT_MAX;
        int minm1 = INT_MAX;

        ll repCnt = 0;
        int index = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                repCnt += 1;
                index = i;
            }
        }
        int i = 1;
        while (i < n && (arr[i] <= 0))
        {
            ll temp = abs(arr[i - 1] - arr[i]);
            if (temp < minm)
            {
                minm = temp;
            }
            i++;
        }
        // cout << minm << endl;
        ll count = 0;
        if (repCnt > 1)
        {
            count = index + 1;
        }
        else if (repCnt == 1)
        {
            if (index + 1 < n)
            {
                if (abs(arr[index] - arr[index + 1]) <= minm)
                {
                    count = index + 2;
                }
                else
                {
                    count = index + 1;
                }
            }
            else
            {
                count = index + 1;
            }
        }
        else
        {
            bool flag = false;
            for (int i = 0; i < n; i++)
            {
                if (arr[i] > 0)
                {
                    if (i == 0)
                    {
                        count = 1;
                        flag = true;
                        break;
                    }
                    else
                    {

                        // ll tmp = abs(arr[i - 1] - arr[i]);
                        if (arr[i] <= minm)
                        {
                            count = i + 1;
                        }
                        else
                        {
                            count = i;
                        }
                        flag = true;
                        break;
                    }
                }
            }
            if (!flag)
            {
                count = n;
            }
        }
        cout << count << endl;
    }
    return 0;
}