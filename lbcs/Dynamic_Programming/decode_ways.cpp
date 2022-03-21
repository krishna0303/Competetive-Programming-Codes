#include <bits/stdc++.h>
using namespace std;

int numDecodings(string A)
{
    vector<int> dp(A.size() + 1, 0);
    dp[0] = 1;
    if (A[0] == '0')
        dp[1] = 0;
    else
        dp[1] = 1;
    for (int i = 2; i <= A.size(); i++)
    {
        if (A[i - 1] > '0')
            dp[i] = dp[i - 1];
        if ((A[i - 2] == '1') || (A[i - 2] == '2' && A[i - 1] < '7'))
            dp[i] = (dp[i - 2] + dp[i]) % 1000000007;
    }
    return dp[A.size()];
}
int helper(string &s, vector<int> &dp, int index)
{
    int mod = pow(10, 9) + 7;
    if (index == s.length())
    {
        return dp[index] = 1;
    }
    if (s[index] == '0')
    {
        return dp[index] = 0;
    }
    if (dp[index] != -1)
    {
        return dp[index];
    }
    if (dp[index + 1] == -1)
    {
        dp[index + 1] = (helper(s, dp, index + 1) % mod);
    }
    int res = dp[index + 1];
    if (index + 1 < s.length() && (s[index] == '1' || (s[index] == '2' && s[index + 1] <= '6')))
    {
        if (dp[index + 2] == -1)
        {
            dp[index + 2] = (helper(s, dp, index + 2) % mod);
        }
        res = (res + dp[index + 2]) % mod;
    }
    return dp[index] = res;
}
int numDecodings(string A)
{
    vector<int> dp(A.length() + 1, -1);
    return helper(A, dp, 0);
}

int ways(const string &A, int s)
{
    if (s == A.size())
        return 1;
    else if (A[s] == '0')
        return 0;
    else if (A[s] > '2')
        return ways(A, s + 1);
    else if (s + 1 >= A.size())
        return ways(A, s + 1);
    else if (A[s] == '1' || (A[s] == '2' && A[s + 1] < '7'))
        return ways(A, s + 1) + ways(A, s + 2);
    else
        return ways(A, s + 1);
}

int numDecodings(string A)
{
    return ways(A, 0);
}
