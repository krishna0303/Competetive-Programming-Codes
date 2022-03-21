// { Driver Code Starts

/*
Given a string 'str' of size ‘n’. The task is to remove or delete the minimum number of characters
from the string so that the resultant string is a palindrome. Find the minimum numbers of characters we need to remove.
Note: The order of characters should be maintained.

Example 1:

Input: n = 7, str = "aebcbda"
Output: 2
Explanation: We'll remove 'e' and
'd' and the string become "abcba".

*/
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

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
        cout << minDeletions(s, n) << endl;
    }
    return 0;
} // } Driver Code Ends

int dp[1001][1001];

int lcs(string s1, string s2, int n, int m)
{
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}
int minDeletions(string A, int n)
{
    // complete the function here
    string a = A;
    reverse(A.begin(), A.end());
    string b = A;
    return A.length() - lcs(a, b, A.length(), A.length());
}