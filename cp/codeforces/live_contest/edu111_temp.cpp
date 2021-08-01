#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        string s;
        cin >> n >> a >> b;
        cin >> s;
        // int squareRoot = ;
        int ans = 0;
        // int ans1 = n * a + n * b;
        int count = 1;
        char e = s[0], temp = s[0];
        if (b < 0)
        {
            for (int i = 0; i < n; i++)
            {
                if (s[i] != e && s[i] != temp)
                {

                    count += 1;
                }
                e = s[i];
            }
            ans = (n * a) + (count * b);
        }
        else
        {
            ans = (n * a) + (n * b);
        }

        cout << ans << endl;
    }
    return 0;
}