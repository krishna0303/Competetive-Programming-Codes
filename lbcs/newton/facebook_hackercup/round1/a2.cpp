#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;

int main()
{
#ifndef ONLINE_JUDGE

    // For getting input from input.txt file
    freopen("weak_typing_chapter_2_input.txt", "r", stdin);

    // Printing the Output to output.txt file
    freopen("A2_chapter1_output.txt", "w", stdout);

#endif
    ll t;
    cin >> t;
    ll k = 1;
    while (k <= t)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        vector<ll> v, fst;
        bool flag = false;
        v.push_back(0);
        for (ll i = 0; i < n;)
        {
            if (s[i] == 'X')
            {
                ll index = i;
                ll count = 0;
                while (i < n && s[i] != 'O')
                {
                    if (s[i] == 'X')
                    {
                        index = i;
                    }
                    count += 1;
                    i++;
                }
                v.push_back(index + 1);
                fst.push_back(count);
            }
            else if (s[i] == 'O')
            {
                ll index = i;
                ll count = 0;

                while (i < n && s[i] != 'X')
                {
                    if (s[i] == 'O')
                    {
                        index = i;
                    }
                    count += 1;
                    i++;
                }
                v.push_back(index + 1);
                fst.push_back(count);
            }
            else
            {
                i++;
            }
        }
        reverse(v.begin(), v.end());
        reverse(fst.begin(), fst.end());
        // for (int i = 0; i < v.size(); i++)
        // {
        //     cout << v[i] << " ";
        // }
        // cout << endl;
        ll ans = 0;

        for (ll i = 0; i < v.size() - 1; i++)
        {
            // // cout << v[i] << " ";
            // int a = abs(v[i] - v[i + 1]);
            // long long small = (i * (2 * a + (n - 1) * a)) / 2;
            // small = (small % mod * fst[i - 1] % mod) % mod;
            // ans = ans + small % mod;
            ll small = 0;
            ll count = 1;
            for (ll j = i + 1; j < v.size() - 1; j++)
            {
                ll a = abs(v[j] - v[j + 1]);
                small = small + (a % mod * count % mod) % mod;
                count++;
            }
            small = (small % mod * fst[i] % mod) % mod;
            ans = ans + small % mod;
        }

        cout << "Case #" << k << ": " << ans % mod << endl;
        k++;
    }
    return 0;
}