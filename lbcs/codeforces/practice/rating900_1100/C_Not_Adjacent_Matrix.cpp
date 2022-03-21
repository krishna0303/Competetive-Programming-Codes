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
        int arr[n][n];
        if (n == 2)
        {
            cout << -1 << endl;
            continue;
        }
        int x = 1, y = n * n;
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (flag)
                {
                    arr[i][j] = x;
                    x++;
                    flag = false;
                }
                else
                {
                    arr[i][j] = y;
                    y--;
                    flag = true;
                }
            }
        }
        arr[0][0] = arr[n - 1][n - 1];
        arr[n - 1][n - 1] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}