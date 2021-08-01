#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int *arr = new int[2 * n];
    for (int i = 0; i < (2 * n); i++)
    {
        cin >> arr[i];
    }
    int ans = 0;
    int *temp = new int[2 * n];
    temp = arr;

    if (n % 2 == 0)
    {
        int count = 0;
        while (true)
        {
            if (count % 2 == 0)
            {
                int i = 0;
                while (i < 2 * n)
                {
                    swap(arr[i], arr[i + 1]);
                    i += 2;
                }
            }
            else
            {
                int i = 0;
                int j = n;
                while (i < n && j < (2 * n))
                {
                    swap(arr[i], arr[j]);
                    i += 1;
                    j += 1;
                }
            }
            bool flag = true;
            for (int i = 0; i < (2 * n) - 1; i++)
            {
                if (arr[i] + 1 != arr[i + 1])
                {
                    flag = false;
                    break;
                }
            }
            if (!flag)
            {
                bool flag1 = true;
                for (int j = 0; j < (2 * n); j++)
                {
                    if (arr[j] != temp[j])
                    {
                        flag1 = false;
                    }
                }
                if (flag1)
                {
                    ans = -1;
                    break;
                }
            }
            else
            {
                ans = count;
            }
            count += 1;
        }
        cout << ans << endl;
    }
    return 0;
}