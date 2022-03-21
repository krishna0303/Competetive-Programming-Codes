#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
int main()
{
#ifndef ONLINE_JUDGE

    // For getting input from input.txt file
    freopen("weak_typing_chapter_2_input.txt", "r", stdin);

    // Printing the Output to output.txt file
    freopen("A_chapter1_output.txt", "w", stdout);

#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    for (int p = 1; p <= t; p++)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        ll cnt1 = 0;
        ll cnt2 = 0;
        int flag1 = 0;
        int flag = 0;
        ll ans = 0;
        for (int j = 0; j < n; j++)
        {
            ll cnt1 = 0;
            ll cnt2 = 0;
            int flag1 = 0;
            int flag = 0;
            for (int i = j; i < s.size(); i++)
            {
                if (flag1 == 0 && s[i] == 'O')
                {
                    flag1 = 1;
                    cnt1++;
                }
                if (flag1 == 1 && s[i] == 'X')
                {
                    flag1 = 0;
                    cnt1++;
                }
                if (flag == 0 && s[i] == 'X')
                {
                    flag = 1;
                    cnt2++;
                }
                if (flag == 1 && s[i] == 'O')
                {
                    flag = 0;
                    cnt2++;
                }
                ll k = min(cnt1, cnt2);
                ans += k;
                ans %= mod;
            }
        }
        cout << "Case #" << p << ": " << ans << endl;
    }
}