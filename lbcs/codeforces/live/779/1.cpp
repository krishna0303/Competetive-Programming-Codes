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
        int mCount = 0;
        int fCount = 0;
        int req = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '0')
            {
                mCount += 1;
            }
            else
            {
                fCount += 1;
            }
            if (i != 0 && s[i] == '0' && s[i] == s[i - 1])
            {
                req += 2;
                fCount += 1;
            }
            if (i != 0 && mCount > fCount)
            {
                req += (mCount - fCount) + 1;
                fCount += 1;
            }
        }
        cout << req << endl;
    }
    return 0;
}
