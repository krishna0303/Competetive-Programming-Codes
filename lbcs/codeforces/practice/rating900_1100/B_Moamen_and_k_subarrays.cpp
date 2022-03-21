#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//https://codeforces.com/problemset/problem/1557/B

/*

idea is to sort the arerya and store it in another array and now compare count how many minimum subarray we can
form sot that we can sort the array by using given steps

*/
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll *arr = new ll[n];
        ll *sorted = new ll[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            sorted[i] = arr[i];
        }
        sort(sorted, sorted + n);
        ll count = 1;
        map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            m[sorted[i]] = i;
        }
        for (int i = 1; i < n; i++)
        {
            if (arr[i - 1] < arr[i])
            {
                int index = m[arr[i]];
                if (index > 0 && sorted[index - 1] != arr[i - 1])
                {
                    count += 1;
                }
            }
            else
            {
                count += 1;
            }
        }
        if (count > k || k > n)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }
    return 0;
}