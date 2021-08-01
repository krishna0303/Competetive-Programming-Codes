#include <bits/stdc++.h>
using namespace std;

/*

for better understanding watch this video https://www.youtube.com/watch?v=l6qlrWyoVv0

we have to traverse from right side and check the condition



*/
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        int ans = 1;
        long long c1 = 0, c2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == '1')
            {
                c1 += 1;
            }
            else
            {
                c2 += 1;
            }
        }
        bool changed = false;
        bool flag = false;
        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] == b[i])
            {
                if (changed == false)
                {
                    if (a[i] == '1')
                    {
                        c1 -= 1;
                    }
                    else
                    {
                        c2 -= 1;
                    }
                }
                else
                {
                    if (c1 != c2)
                    {
                        cout << "NO" << endl;
                        flag = true;
                        break;
                    }
                    else
                    {
                        if (a[i] == '1')
                        {
                            c1 -= 1;
                        }
                        else
                        {
                            c2 -= 1;
                        }
                        changed = false;
                    }
                }
            }
            else
            {
                if (changed == true)
                {
                    if (a[i] == '1')
                    {
                        c1 -= 1;
                    }
                    else
                    {
                        c2 -= 1;
                    }
                }
                else
                {
                    if (c1 != c2)
                    {
                        cout << "NO" << endl;
                        flag = true;
                        break;
                    }
                    else
                    {
                        if (a[i] == '1')
                        {
                            c1 -= 1;
                        }
                        else
                        {
                            c2 -= 1;
                        }
                        changed = true;
                    }
                }
            }
        }
        if (!flag)
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}