// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        int **dp = new int *[x + 1];
        for (int i = 0; i <= x; i++)
        {
            dp[i] = new int[y + 1];
            for (int j = 0; j <= y; j++)
            {
                dp[i][j] = -1;
            }
        }
        for (int i = 0; i <= x; i++)
        {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= y; i++)
        {
            dp[0][i] = 0;
        }
        for (int i = 1; i <= x; i++)
        {
            for (int j = 1; j <= y; j++)
            {
                if (s1[i - 1] != s2[j - 1] || i == j)
                { // everything is similar to lcs only diffrence  is i!=j so we will pass same string tweo times and if both characters are same but at different possiition then increament by 1 otherwise if same character but index is same then it will increament the answer we have to return previous maxvalue
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
                else
                {

                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
            }
        }
        return dp[x][y];
    }

    int LongestRepeatingSubsequence(string str)
    {
        // Code here
        return lcs(str.length(), str.length(), str, str);
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string str;
        cin >> str;
        Solution obj;
        int ans = obj.LongestRepeatingSubsequence(str);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends