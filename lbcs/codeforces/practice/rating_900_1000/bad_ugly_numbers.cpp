#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(ll sum, int n)
{
    int l = 2;
    if (n < 8)
    {
        l = 9 - n + 1;
    }
    // if (sum % k == 0)
    // {
    //     return true;
    // }
    for (int i = l; i <= 9; i++)
    {
        if (sum % i == 0)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n == 1)
        {
            cout << -1 << endl;
        }
        else
        {
            string s = "";
            bool flag = true;
            while (n--)
            {
                if (flag)
                {
                    s += "2";
                    flag = false;
                }
                else
                {
                    s += "3";
                }
            }

            // reverse(s.begin(), s.end());
            cout << s << endl;
        }
    }
    return 0;
}