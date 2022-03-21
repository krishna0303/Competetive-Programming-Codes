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
        int l1 = 0, e1 = 0, g1 = 0;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '<')
            {
                l1 += 1;
            }
            else if (s[i] == '>')
            {
                g1 += 1;
            }
            else
            {
                e1 += 1;
            }

        }
        if(l1>0&&){

        }

    }
    return 0;
}