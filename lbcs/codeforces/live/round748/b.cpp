#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string s = to_string(n);
        int m = s.length();
        int i;
        int minCount = INT_MAX;

        for (int j = m - 1; j >= 0; j--)
        {
            int count = m - 1 - j;
            char ch;
            i = j;

            while (i >= 0)
            {
                if (s[i] == '0' || s[i] == '5')
                {
                    ch = s[i];
                    break;
                }
                else
                {
                    count += 1;
                }
                i--;
            }
            i--;
            bool flag = false;
            while (i >= 0)
            {
                if (ch == '5')
                {
                    if (s[i] == '2' || s[i] == '7')
                    {
                        flag = true;
                        break;
                    }
                    else
                    {
                        count += 1;
                    }
                }
                else if (ch == '0')
                {
                    if (s[i] == '5' || s[i] == '0')
                    {
                        flag = true;
                        break;
                    }
                    else
                    {
                        count += 1;
                    }
                }
                i--;
            }

            if (flag)
            {
                // cout << count << endl;
                minCount = min(minCount, count);
            }
            else
            {
                minCount = min(minCount, INT_MAX);
            }
        }

        cout << minCount << endl;
    }
    return 0;
}