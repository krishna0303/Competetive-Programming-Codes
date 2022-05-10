
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        map<string, bool> m;
        m["aa"] = true;
        m["aaa"] = true;
        m["bb"] = true;
        m["bbb"] = true;

        string str = "";
        bool flag = false;
        if (s.length() == 1)
        {
            flag = true;
        }
        for (int i = 1; i < s.length();)
        {
            int count = 1;

            while (i < s.length() && s[i - 1] == s[i])
            {
                i++;
                count += 1;
            }
            i++;
            // cout << count << endl;

            if (count < 2)
            {
                flag = true;
            }
        }
        int n = s.length();
        if (s[n - 1] != s[n - 2])
        {
            flag = true;
        }
        if (!flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
