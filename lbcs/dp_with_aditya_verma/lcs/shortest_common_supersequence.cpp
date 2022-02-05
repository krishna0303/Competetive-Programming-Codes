// { Driver Code Starts
//Initial template for C++
/*
Given two strings X and Y of lengths m and n respectively, find the length of the smallest string which has both, X and Y as its sub-sequences.
Note: X and Y can have both uppercase and lowercase letters.

Example 1

Input:
X = abcd, Y = xycd
Output: 6
Explanation: Shortest Common Supersequence
would be abxycd which is of length 6 and
has both the strings as its subsequences.

*/

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

int dp[101][101];
class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int lcsUtil(string s1,string s2,int n,int m){
        for(int i=0;i<n;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<m;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
        int common=lcsUtil(X,Y,m,n);
        return (m+n)-common;
    }
};

// { Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}

  // } Driver Code Ends