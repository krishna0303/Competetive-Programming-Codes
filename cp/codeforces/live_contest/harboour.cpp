#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;

        int n = str.length();
        int q1 = 0, s1 = 0, l1 = 5;

        int q2 = 0, s2 = 0, l2 = 5;
        bool flag = false;
        int i = 0;

        for (; i < n; i++)
        {
            if (i % 2 == 0)
            {
                q1 += (str[i] == '?');
                s1 += (str[i] == '1');
                l1 -= 1;
            }
            else
            {
                q2 += (str[i] == '?');
                s2 += (str[i] == '1');
                l2 -= 1;
            }
            int a1 = s1;
            int a2 = s2 + q2;
            int d = a2 - a1;

            if (d > l1)
            {
                flag = true;
                break;
            }

            a1 = s1 + q1;
            a2 = s2;
            d = a1 - a2;
            
            if (d > l2)
            {
                flag = true;
                break;
            }
        }
        if (flag)
        {
            cout << i + 1 << endl;
        }
        else
        {
            cout << i << endl;
        }
    }
    return 0;
}