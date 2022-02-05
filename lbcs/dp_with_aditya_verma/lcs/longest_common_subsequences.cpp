// { Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence

int dp[1001][1001];
class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    //Recursive
    // int lcsUtil(string s1,string s2,int n,int m){
    //     if(n==0||m==0){
    //         return 0;
    //     }
    //     if(dp[n][m]!=-1){
    //         return dp[n][m];
    //     }
    //     if(s1[n-1]==s2[m-1]){
    //         return dp[n][m]=1+lcsUtil(s1,s2,n-1,m-1);
    //     }else{
    //         return dp[n][m]=max(lcsUtil(s1,s2,n-1,m),lcsUtil(s1,s2,n,m-1));
    //     }
    // }
    
    //Top-Down approach
    
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
    
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        // memset(dp,-1,sizeof(dp));
        return lcsUtil(s1,s2,x,y);
    }
};


// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
  // } Driver Code Ends