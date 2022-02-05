// { Driver Code Starts
#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

int dp[1001][1001];
class Solution
{
public:
    // Top-Down approach

    int lcsUtil(string s1, string s2, int n, int m)
    {
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 0;
        }
        for (int i = 0; i < m; i++)
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
    }

    string printLCS(int x, int y, string s1, string s2)
    {
        // your code here
        // memset(dp,-1,sizeof(dp));
        lcsUtil(s1, s2, x, y);
        int i = x;
        int j = y;
        string str = "";
        while (i > 0 && j > 0)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                str += s1[i - 1];
                i--;
                j--;
            }
            else
            {
                if (dp[i][j - 1] > dp[i - 1][j])
                {
                    j--;
                }
                else
                {
                    i--;
                }
            }
        }
        reverse(str.begin(), str.end());
        return str;
    }
};

// { Driver Code Starts.
int main()
{
    int t, n, k, x, y;
    cin >> t;
    while (t--)
    {
        cin >> x >> y; // Take size of both the strings as input
        string s1, s2;
        cin >> s1 >> s2; // Take both the string as input
        Solution ob;
        cout << ob.printLCS(x, y, s1, s2) << endl;
    }
    return 0;
}
// } Driver Code Ends