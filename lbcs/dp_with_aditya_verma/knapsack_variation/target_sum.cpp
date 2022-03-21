// { Driver Code Starts
//Initial Template for C++
/*
Given an array of integers A[] of length N and an integer target.
You want to build an expression out of A by adding one of the symbols '+' and '-' before each integer in A and then concatenate all the integers.

For example, if arr = {2, 1}, you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that can be built, which evaluates to target.


Example 1:

Input:
N = 5
A[] = {1, 1, 1, 1, 1}
target = 3
Output:
5
Explanation:
There are 5 ways to assign symbols to 
make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

*/

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++

class Solution
{
public:
    int help(vector<int> &a, int tar, int n)
    {
        int dp[n + 1][tar + 1];

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= tar; j++)
            {
                if (i == 0)
                {
                    dp[i][j] = 0;
                }
                if (j == 0)
                {
                    dp[i][j] = 1;
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= tar; j++)
            {
                if (a[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i - 1]];
                }

                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][tar];
    }
    int findTargetSumWays(vector<int> &A, int tar)
    {

        int n = A.size();
        int s = 0;
        for (int i = 0; i < n; i++)
        {
            s += A[i];
        }
        int sum = (tar + s) / 2;

        if ((tar + s) % 2 != 0)
        {
            return 0;
        }
        return help(A, sum, n);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;

        cin >> N;
        vector<int> arr(N);

        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout << ob.findTargetSumWays(arr, target);
        cout << "\n";
    }
    return 0;
} // } Driver Code Ends