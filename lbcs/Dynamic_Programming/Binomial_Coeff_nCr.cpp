// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
////P(n, k) = P(n-1, k) + k* P(n-1, k-1)   formula to calculate permuation coeffficient
#define mod 1000000007
class Solution{
public:
    
    long long int dp[1001][801];
    
    int nCr(int n, int r){
        // code here
        if(r>n){
            return 0;
        }
        
        
        dp[n+1][r+1];
        for(int i=0;i<=r;i++){
            dp[0][i]=0;
        }
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=r;j++){
                dp[i][j]=(dp[i-1][j]%mod+dp[i-1][j-1]%mod)%mod;
                
            }
        }
        return dp[n][r]%mod;
        
        
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends