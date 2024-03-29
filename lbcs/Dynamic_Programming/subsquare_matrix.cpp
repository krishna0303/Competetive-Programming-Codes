// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

/*

idea is to fill the last column and last row in dp array as it is
then from i=n-2 to 0 and then j=m-2 to 0 
check below conditions for understand the logiv basically i'm filling this table from bottom to top order

for understanding dry run this
0 1 1 0 1
1 1 1 0 1
0 1 1 1 0
1 1 1 1 1
0 1 1 1 0

answer should be 3



*/
    int maxSquare(int n, int m, vector<vector<int>> mat){
        
        int dp[n][m];
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         // dp[i][j]=0;
        //         cout<<mat[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        for(int i=0;i<m;i++){
            dp[n-1][i]=mat[n-1][i];
        }
        for(int i=0;i<n;i++){
            dp[i][m-1]=mat[i][m-1];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                if(mat[i][j]==0){
                    dp[i][j]=0;
                }else{
                    dp[i][j]=1+min(dp[i][j+1],min(dp[i+1][j+1],dp[i+1][j]));
                }
            }
        }
        int maxm=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxm=max(maxm,dp[i][j]);
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        return maxm;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends