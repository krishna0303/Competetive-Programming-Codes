#include <bits/stdc++.h>
using namespace std;

string squareColor(string s, int n, string str, map<int, pair<string, string>> dp)
{
    if (n == 0)
    {
        dp[n] = make_pair(str, str);
        return str;
    }
    if (dp[n].second != "#" && dp[n].first == str)
    {
        cout << "come here" << endl;
        return dp[n].second;
    }
    if (s[n - 1] != '?')
    {
        dp[n] = make_pair(str, squareColor(s, n - 1, str + s[n - 1], dp));
        return dp[n].second;
    }
    else
    {
        string s1 = squareColor(s, n - 1, str + 'R', dp);
        string s2 = squareColor(s, n - 1, str + 'B', dp);
        int count1 = 0;
        int count2 = 0;
        for (int i = 1; i < s1.length(); i++)
        {

            if (s1[i] == s1[i - 1])
            {
                count1 += 1;
            }
        }
        for (int i = 1; i < s2.length(); i++)
        {

            if (s2[i] == s2[i - 1])
            {
                count2 += 1;
            }
        }
        if (count1 < count2)
        {
            dp[n] = make_pair(str, s1);
            return dp[n].second;
        }
        else
        {
            dp[n] = make_pair(str, s2);
            return dp[n].second;
        }
    }
}
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
        map<int, pair<string, string>> dp;
        for (int i = 0; i <= n; i++)
        {
            dp[i] = make_pair("", "#");
        }
        string ans = squareColor(s, n, "", dp);
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
    return 0;
}
