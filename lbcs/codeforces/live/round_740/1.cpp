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
        int ans;
        bool flag = false;
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                flag = true;
                break;
            }
        }
        if (flag == false)
        {
            ans = 0;
        }
        else
        {
            int maxCount = 0;
            int i = 1;
            while (true)
            {
                // if (i % 2 != 0)
                // {
                //     n = n - 1;
                // }
                int count = 0;
                int j = (i % 2 == 0 ? 1 : 0);
                for (; j < n - 1;)
                {
                    if (arr[j] > arr[j + 1])
                    {
                        int temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                        j += 2;
                    }
                    else
                    {
                        j += 2;
                    }
                }
                // for (int k = 0; k < n; k++)
                // {
                //     cout << arr[k] << " ";
                // }
                // cout << endl;
                bool flag1 = false;
                for (int k = 0; k < n - 1; k++)
                {
                    if (arr[k] > arr[k + 1])
                    {
                        flag1 = true;
                    }
                }
                maxCount += 1;

                if (!flag1)
                {
                    ans = maxCount;
                    break;
                }
                i += 1;
            }
        }

        cout << ans << endl;
    }
    return 0;
}