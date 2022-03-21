#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll *arr = new ll[n + 1];
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        int count = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = arr[i] - i; j <= n; j += arr[i])
            {
                if (j >= 0)
                {
                    if ((arr[i] * arr[j]) == (i + j) && (i < j))
                    {
                        count += 1;
                    }
                }
            }
        }
        cout << count << endl;
    }

    return 0;
}