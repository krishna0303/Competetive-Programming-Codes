// { Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    long long int dp[1001][1001];
    
    long long int countPalindrome(int i,int j,string s){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i==j){
            return 1;
        }
        
        else if(s[i]==s[j]){
            return dp[i][j]=1+(countPalindrome(i+1,j,s)%(1000000007)+countPalindrome(i,j-1,s)%(1000000007))%(1000000007);
        }else{
            return dp[i][j]=(countPalindrome(i+1,j,s)%(1000000007)+countPalindrome(i,j-1,s)%(1000000007)-countPalindrome(i+1,j-1,s)%(1000000007))%(1000000007);
            
        }
    }
    long long int  countPS(string str)
    
    {
        int n=str.length();
        dp[n][n];
        memset(dp, -1,sizeof(dp));
        return countPalindrome(0,n-1,str)%(1000000007);
        
       //Your code here
    }
     
};

// { Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}  // } Driver Code Ends