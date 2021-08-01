#include <bits/stdc++.h>
using namespace std;

// for better understanding of this approach watch https://www.youtube.com/watch?v=vHavxvnCxik
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long *arr = new long long[n + 1];
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = arr[i] - i; j <= n; j += arr[i])
            {
                if (j >= 0)
                {
                    if (arr[i] * arr[j] == i + j && i < j)
                    {
                        ans += 1;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}