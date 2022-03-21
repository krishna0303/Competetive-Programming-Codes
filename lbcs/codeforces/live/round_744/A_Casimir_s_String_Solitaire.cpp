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
        int c1 = 0, c2 = 0, c3 = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'A')
            {
                c1 += 1;
            }
            else if (s[i] == 'B')
            {
                c2 += 1;
            }
            else
            {
                c3 += 1;
            }
        }
        if (c1 + c3 == c2)
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
