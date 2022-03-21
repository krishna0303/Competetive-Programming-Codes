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
        string s;
        cin >> s;

        int c1 = 0, c2 = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'T')
            {
                c1 += 1;
            }
            else
            {
                c2 += 1;
            }
        }
        int tcount = 0, mcount = 0;
        bool flag = false;
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'T')
            {
                tcount += 1;
            }
            else
            {
                mcount += 1;
            }
            if (tcount < mcount)
            {
                flag = true;
                break;
            }
        }
        tcount = 0, mcount = 0;
        if (!flag)
        {
            for (int i = n - 1; i >= 0; i--)
            {
                if (s[i] == 'T')
                {
                    tcount += 1;
                }
                else
                {
                    mcount += 1;
                }
                if (tcount < mcount)
                {
                    flag = true;
                    break;
                }
            }
        }
        if ((2 * c2) != c1 || flag)
        {
            ans = "NO";
        }
        else
        {
            ans = "YES";
        }

        cout << ans << endl;
    }
    return 0;
}