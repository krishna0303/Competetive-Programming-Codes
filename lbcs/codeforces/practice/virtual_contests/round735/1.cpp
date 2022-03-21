#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        long long int *arr = new long long int[n];
        for (long long int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        // long long int maxm = INT_MIN;
        // // long long int idx = -1;
        // for (long long int i = 0; i < n; i++)
        // {
        //     if (arr[i] > maxm)
        //     {
        //         maxm = arr[i];
        //         // idx = i;
        //     }
        // }
        // // cout << idx << endl;
        // // long long int i = idx - 1;
        // long long int minm = INT_MAX;

        // // cout << maxm << endl;
        long long int ans = INT_MIN;
        for (int idx = 0; idx < n; idx++)
        {
            long long int temp1 = INT_MIN;
            long long int temp2 = INT_MIN;
            if ((idx - 1) >= 0)
            {
                temp1 = (arr[idx] * arr[idx - 1]);
            }
            if ((idx + 1) < n)
            {
                temp2 = (arr[idx] * arr[idx + 1]);
            }
            // cout << temp1 << " " << temp2 << endl;
            long long int temp = max(temp1, temp2);
            if (temp > ans)
            {
                ans = temp;
            }
        }

        // while (i >= 0)
        // {
        //     if (minm > arr[i])
        //     {
        //         minm = arr[i];
        //         long long temp = maxm * arr[i];
        //         // cout << temp << endl;
        //         if (temp > ans)
        //         {
        //             ans = temp;
        //         }
        //         else
        //         {
        //             break;
        //         }
        //     }
        //     i--;
        // }
        // int j = idx + 1;
        // minm = INT_MAX;

        // while (j < n)
        // {
        //     if (minm > arr[j])
        //     {
        //         minm = arr[j];

        //         long long temp = maxm * arr[j];
        //         if (temp > ans)
        //         {
        //             ans = temp;
        //         }
        //         else
        //         {
        //             break;
        //         }
        //     }
        //     j++;
        // }
        cout << ans << endl;
    }
}