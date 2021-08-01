#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*

sort the array and so first of all we will check for last element because it is maximum
checking for last element first of all add the sum of all value except last element
and iterate over one by one if subtract each value from the sum of n+1 value if after subtracting if sum is equal to last element 
then it means we found a array so we have to print escape that index which we have subtracted
and if last element is not sum value then we have only one choice it is assuming value
so check for second last eleemtn its all previous value sum should be eual to that second last element then it we will find some a array
so we have to just print it out
otherwise print -1



*/
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll *arr = new ll[n + 2];
        for (int i = 0; i < n + 2; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n + 2);
        ll *dp = new ll[n + 1];
        dp[0] = arr[0];
        for (int i = 1; i < n + 1; i++)
        {
            dp[i] = arr[i] + dp[i - 1];
        }
        ll index = 0;
        ll ans = 0;
        ll val = dp[n];
        // cout << val << endl;
        // cout << arr[n + 1] << endl;
        bool flag = false;
        for (int i = 0; i < n + 1; i++)
        {
            if ((val - arr[i]) == arr[n + 1])
            {
                index = i;
                flag = true;
                break;
            }
        }
        if (flag)
        {
            for (int i = 0; i < n + 1; i++)
            {
                if (i == index)
                {
                    continue;
                }
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else
        {
            if (dp[n - 1] == arr[n])
            {
                for (int i = 0; i < n; i++)
                {
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}