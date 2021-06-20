// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  //bottom -up iterativeor tabular method
//   int editDistance(string s, string t) {
//         // Code here
//         int n=s.length();
//         int m=t.length();
//         dp[n+1][m+1];
        
//         for(int i=0;i<=n;i++){
//             for(int j=0;j<=m;j++){
//                 if(i==0){
//                     dp[i][j]=j;
//                 }
//                 else if(j==0){
//                     dp[i][j]=i;
//                 }
//                 else if(s[i-1]==t[j-1]){
//                     dp[i][j]=dp[i-1][j-1];
                    
//                 }
//                 else{
//                     dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                    
//                 }
                
//             }
//         }
//         return dp[n][m];
//     }
  //top-down approach (recursive method)
     int dp[101][101];
    int editDistanceUtil(string s, string t,int n,int m) {
        // Code here
        if(n==0){
            dp[n][m]=m;
            return m;
        }
        if(m==0){
            dp[m][n]=n;
            return n;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        if(s[n-1]==t[m-1]){
            return dp[n][m]=editDistanceUtil(s,t,n-1,m-1);
        }
        return dp[n][m]=(1+min(editDistanceUtil(s,t,n-1,m),min(editDistanceUtil(s,t,n,m-1),editDistanceUtil(s,t,n-1,m-1))));
    }
    int editDistance(string s, string t) {
        // Code here
        int n=s.length();
        int m=t.length();
        dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                dp[i][j]=-1;
            }
        }
        return editDistanceUtil(s,t,n,m);
    }
        
        
        
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends