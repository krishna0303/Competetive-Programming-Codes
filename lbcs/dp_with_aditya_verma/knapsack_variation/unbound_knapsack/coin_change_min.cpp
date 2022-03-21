// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*
 
 // { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    int dp[M+1][V+1];
	    for(int i=0;i<=V;i++){
	        dp[0][i]=INT_MAX-1;
	    }
	    for(int i=1;i<=M;i++){
	        dp[i][0]=0;
	    }
	   // for(int i=1;i<=V;i++){
	   //     if(i%coins[0]==0){
	   //         dp[1][i]=i/coins[0];
	   //     }else{
	   //         dp[1][i]=INT_MAX-1;
	   //     }
	   // }
	    for(int i=1;i<=M;i++){
	        for(int j=1;j<=V;j++){
	            if(coins[i-1]<=j){
	                dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
	            }else{
	                dp[i][j]=dp[i-1][j];
	            }
	        }
	    }
	    if(dp[M][V]!=(INT_MAX-1)){
	        return dp[M][V];
	    }else{
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
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends
 
 */
class Solution
{

public:
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