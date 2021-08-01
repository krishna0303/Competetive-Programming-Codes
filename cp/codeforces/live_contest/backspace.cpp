#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s, t;
        cin >> s >> t;
        int n = s.length();
        int m = t.length();
        if (m > n)
        {
            cout << "NO" << endl;
        }
        else
        {

            int i = n - 1;
            int j = m - 1;
            bool flag = false;
            bool flag1 = false;

            while (j >= 0 && i >= 0)
            {
                if (t[j] == s[i])
                {
                    flag = true;
                    i--;
                    j--;
                }
                else
                {
                    if (flag)
                    {
                        // cout << i << " " << j << endl;
                        flag1 = true;
                        break;
                    }
                    else
                    {
                        i--;
                    }
                }
            }
            if (!flag1 && flag == true)
            {
                cout << "YES" << endl;
            }
            else 
            {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}