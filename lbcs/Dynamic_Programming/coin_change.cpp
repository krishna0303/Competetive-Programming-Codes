/*
Given a value N, find the number of ways to make change for N cents, 
if we have infinite supply of each of S = { S1, S2, .. , SM } valued coins. 

Example 1:

Input:
n = 4 , m = 3
S[] = {1,2,3}
Output: 4
Explanation: Four Possible ways are:
{1,1,1,1},{1,1,2},{2,2},{1,3}.


*/

/*

idea is to make recursion tree see overlaping
so here there is two possibilities for a value,we can select them or we can't select them
if we select we can kept it on hold

1) Optimal Substructure 
To count the total number of solutions, we can divide all set solutions into two sets. 
1) Solutions that do not contain mth coin (or Sm). 
2) Solutions that contain at least one Sm. 
Let count(S[], m, n) be the function to count the number of solutions, then it can be written as sum of count(S[], m-1, n) and count(S[], m, n-Sm).
Therefore, the problem has optimal substructure property as the problem can be solved using solutions to subproblems.



*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
    long long int dp[1000][1000];
    long long int solve( int S[], int m, int n ){
        if(m<0 and n>0){
            return 0;
        }
        if(n<0){
            return 0;
        }
        if(n==0){
            return 1;
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        
        dp[m][n]=solve(S,m,n-S[m])+solve(S,m-1,n);
        return dp[m][n];
        
    }
    
    long long int count( int S[], int m, int n )
    {
       
        //code here.
        dp[m][n+1];
        for(int i=0;i<m;i++){
            for(int j=0;j<=n;j++){
                dp[i][j]=-1;
            }
        }
        return solve(S,m-1,n);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int arr[m];
		for(int i=0;i<m;i++)
		    cin>>arr[i];
	    Solution ob;
		cout<<ob.count(arr,m,n)<<endl;
	}
    
    
    return 0;
}  // } Driver Code Ends