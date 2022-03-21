// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    /*
// Recursive C++ program for
// coin change problem.
#include <bits/stdc++.h>
using namespace std;

// Returns the count of ways we can
// sum S[0...m-1] coins to get sum n
int count(int S[], int m, int n)
{
	
	// If n is 0 then there is 1 solution
	// (do not include any coin)
	if (n == 0)
		return 1;
	
	// If n is less than 0 then no
	// solution exists
	if (n < 0)
		return 0;

	// If there are no coins and n
	// is greater than 0, then no
	// solution exist
	if (m <= 0 && n >= 1)
		return 0;

	// count is sum of solutions (i)
	// including S[m-1] (ii) excluding S[m-1]
	return count(S, m - 1, n) +
		count(S, m, n - S[m - 1]);
}

// Driver code
int main()
{
	int i, j;
	int arr[] = { 1, 2, 3 };
	int m = sizeof(arr) / sizeof(arr[0]);
	
	cout << " " << count(arr, m, 4);
	
	return 0;
}

// This code is contributed by shivanisinghss2110


*/
    int minCoinsUtil(int coins[], int M, int V, int **dp)
    {
        // Your code goes here
        if (V == 0 && M != 0)
        {
            return 0;
        }
        if (M == 0)
        {
            return INT_MAX - 1;
        }
        if (M == 1 && V != 0)
        {
            if (V % coins[M - 1] == 0)
            {
                return V / coins[M - 1];
            }
            else
            {
                return INT_MAX - 1;
            }
        }
        if (dp[M][V] != -1)
        {
            return dp[M][V];
        }
        if (coins[M - 1] <= V)
        {
            return dp[M][V] = min(1 + minCoinsUtil(coins, M, V - coins[M - 1], dp), minCoinsUtil(coins, M - 1, V, dp));
        }
        else
        {
            return dp[M][V] = minCoinsUtil(coins, M - 1, V, dp);
        }
    }
    int minCoins(int coins[], int M, int V)
    {
        // Your code goes here
        int **dp = new int *[M + 1];
        for (int i = 0; i <= M; i++)
        {
            dp[i] = new int[V + 1];
            for (int j = 0; j <= V; j++)
            {
                dp[i][j] = -1;
            }
        }
        int ans = minCoinsUtil(coins, M, V, dp);
        if (ans != INT_MAX - 1)
        {
            return ans;
        }
        else
        {
            return -1;
        }
    }
};

// { Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for (int i = 0; i < m; i++)
            cin >> coins[i];

        Solution ob;
        cout << ob.minCoins(coins, m, v) << "\n";
    }
    return 0;
}
// } Driver Code Ends