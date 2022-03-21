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
        int *arr1 = new int[n];
        int *arr2 = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> arr2[i];
        }
        sort(arr1, arr1 + n, greater<int>());
        sort(arr2, arr2 + n, greater<int>());
        int ind = n - (n / 4);
        long long my = 0, liya = 0;
        for (int i = 0; i < ind; i++)
        {
            my += arr1[i];
            liya += arr2[i];
        }
        int ans = 0;
        int j = ind;
        if (my < liya)
        {
            while (my < liya)
            {
                my += 100;
                if (j < n)
                {
                    liya += arr2[j];
                    j++;
                }
                ans += 1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
