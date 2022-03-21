#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int ans = 0;
        bool flag = false;
        for (int i = 1; i < n; i++)
        {
            if (arr[i - 1] > arr[i])
            {
                flag = true;
            }
        }
        if (flag)
        {

            if (arr[0] == 1 || arr[n - 1] == n)
            {
                ans = 1;
            }
            else if (arr[0] == n && arr[n - 1] == 1)
            {
                ans = 3;
            }
            else
            {
                ans = 2;
            }
        }
        cout << ans << endl;
    }

    return 0;
}