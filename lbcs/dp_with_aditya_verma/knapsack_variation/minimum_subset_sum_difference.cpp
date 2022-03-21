// { Driver Code Starts
/*

Given an integer array arr of size N, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum and find the minimum difference


Example 1:

Input: N = 4, arr[] = {1, 6, 11, 5} 
Output: 1
Explanation: 
Subset1 = {1, 5, 6}, sum of Subset1 = 12 
Subset2 = {11}, sum of Subset2 = 11   

typical sum for better understanding watch aditya verma videos

*/
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    int minDifference(int arr[], int n)
    {
        // Your code goes here
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }

        bool dp[n + 1][sum + 1];
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < sum + 1; j++)
            {
                if (i == 0)
                {
                    dp[i][j] = false;
                }
                if (j == 0)
                {
                    dp[i][j] = true;
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                if (arr[i - 1] <= j)
                {
                    dp[i][j] = (dp[i - 1][j - arr[i - 1]]) || (dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        int minm = INT_MAX;
        vector<int> v;
        for (int i = 0; i <= sum / 2; i++)
        {
            // cout<<dp[n][i]<<" ";
            if (dp[n][i])
            {
                v.push_back(i);
            }
        }
        for (int i = 0; i < v.size(); i++)
        {
            minm = min(minm, sum - 2 * v[i]);
        }
        return minm;
    }
};

// { Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.minDifference(a, n) << "\n";
    }
    return 0;
} // } Driver Code Ends