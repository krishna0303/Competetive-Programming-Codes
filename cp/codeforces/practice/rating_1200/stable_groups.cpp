#include <bits/stdc++.h>
using namespace std;

// for better understanding of this approach watch https://www.youtube.com/watch?v=vHavxvnCxik
int main()
{

    long long n, k, x;
    cin >> n >> k >> x;
    long long *arr = new long long[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // int ans = 0;
    sort(arr, arr + n);
    long long count = 1;
    for (int i = 1; i < n; i++)
    {
        if (abs(arr[i] - arr[i - 1]) > x)
        {
            if (k > 0)
            {
                long long val = arr[i] - arr[i - 1];
                long long c = val / x;
                if ((val % x == 0) && k >= c - 1)
                {
                    k -= c - 1;
                }
                else if (val % x != 0 && k >= c)
                {
                    k -= c;
                }
                else
                {
                    count += 1;
                }
            }
            else
            {
                count += 1;
            }
        }
    }
    long long count1 = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (abs(arr[i + 1] - arr[i]) > x)
        {
            if (k > 0)
            {
                long long val = arr[i + 1] - arr[i];
                long long c = val / x;
                if ((val % x == 0) && k >= c - 1)
                {
                    k -= c - 1;
                }
                else if (val % x != 0 && k >= c)
                {
                    k -= c;
                }
                else
                {
                    count1 += 1;
                }
            }
            else
            {
                count1 += 1;
            }
        }
    }

    cout << min(count, count1) << endl;

    return 0;
}