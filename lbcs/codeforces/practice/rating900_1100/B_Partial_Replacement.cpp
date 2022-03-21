#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        // int i=0,j=n-1;
        int count = 0;
        bool flag = false;
        int i = 0;
        for (; i < n;)
        {
            cout << i << endl;
            if (!flag)
            {
                if (s[i] == '*')
                {
                    s[i] = 'x';
                    count += 1;
                    i += k;
                    flag = true;
                }
                else
                {
                    i++;
                }
            }
            else
            {
                if (s[i] != '*')
                {
                    int j = i;
                    while (i > (j - k))
                    {
                        if (s[i] == '*')
                        {
                            s[i] = 'x';
                            count += 1;
                            i += k;
                            break;
                        }
                        else
                        {
                            i--;
                        }
                    }
                }
                else
                {
                    count += 1;
                    i += k;
                }
            }
        }
        int j = i;
        i = n - 1;
        while (i >= (j - k))
        {
            if (s[i] == '*')
            {
                s[i] = 'x';
                count += 1;
                i += k;
                break;
            }
            else
            {
                i--;
            }
        }
        cout << count << endl;
    }
    return 0;
}