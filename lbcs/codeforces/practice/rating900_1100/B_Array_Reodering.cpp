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
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if ((__gcd(arr[i], 2 * arr[j]) > 1) || (__gcd(2 * arr[i], arr[j]) > 1))
                {
                    count += 1;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}