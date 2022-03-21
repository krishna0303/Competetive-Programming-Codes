#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE

    // For getting input from input.txt file
    freopen("xs_and_os_input.txt", "r", stdin);

    // Printing the Output to output.txt file
    freopen("chapter_2_output.txt", "w", stdout);

#endif
    int t;
    cin >> t;
    int k = 1;
    while (k <= t)
    {
        int n;
        cin >> n;
        char **arr = new char *[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = new char[n];
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }
        int minCnt = INT_MAX;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int xcnt = 0;
            int ecnt = 0;
            bool flag = true;
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] == 'O')
                {
                    flag = false;
                    break;
                }
                else
                {
                    if (arr[i][j] == 'X')
                    {
                        xcnt += 1;
                    }
                    else
                    {

                        ecnt += 1;
                    }
                }
            }
            if (flag)
            {
                if (ecnt < minCnt)
                {
                    minCnt = ecnt;
                    ans = 1;
                }
                else if (ecnt == minCnt)
                {
                    ans += 1;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            int xcnt = 0;
            int ecnt = 0;
            bool flag = true;
            for (int j = 0; j < n; j++)
            {
                if (arr[j][i] == 'O')
                {
                    flag = false;
                    break;
                }
                else
                {
                    if (arr[j][i] == 'X')
                    {
                        xcnt += 1;
                    }
                    else
                    {
                        ecnt += 1;
                    }
                }
            }
            if (flag)
            {
                if (ecnt < minCnt)
                {
                    minCnt = ecnt;
                    ans = 1;
                }
                else if (ecnt == minCnt)
                {
                    ans += 1;
                }
            }
        }
        if (minCnt == 1)
        {

            for (int i = 0; i < n; i++)
            {
                int xcnt = 0;
                int ecnt = 0;
                bool flag = true;
                int index = 0;
                for (int j = 0; j < n; j++)
                {
                    if (arr[i][j] == 'O')
                    {
                        flag = false;
                        break;
                    }
                    else
                    {
                        if (arr[i][j] == 'X')
                        {
                            xcnt += 1;
                        }
                        else
                        {
                            index = j;
                            ecnt += 1;
                        }
                    }
                }
                if (flag)
                {

                    if (ecnt == 1)
                    {
                        int k = i - 1;
                        int et = 0;
                        int index2 = 0;
                        int xcnt1 = 0;
                        for (int j = 0; j < n; j++)
                        {
                            if (arr[j][index] == 'O')
                            {
                                flag = false;
                                break;
                            }
                            else
                            {
                                if (arr[j][index] == 'X')
                                {
                                    xcnt1 += 1;
                                }
                                else
                                {

                                    et += 1;
                                    index2 = j;
                                }
                            }
                        }
                        if (index == index2 && et == ecnt)
                        {
                            ans -= 1;
                        }
                    }
                }
            }
        }
        if (ans == 0)
        {
            cout << "Case #" << k << ": Impossible" << endl;
        }
        else
        {
            cout << "Case #" << k << ": " << minCnt << " " << ans << endl;
        }
        k++;
    }
    return 0;
}