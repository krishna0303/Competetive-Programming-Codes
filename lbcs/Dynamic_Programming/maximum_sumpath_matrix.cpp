// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
/*

idea is fill last row in dp and iterate from n-2 row
and then select maximum value path from three path and then add the matrix value and the maximum value obtain from below three location
Matrix [r+1] [c]
Matrix [r+1] [c-1]
Matrix [r+1] [c+1]

and finally return the maximum value of first row


*/
    int maximumPath(int n, vector<vector<int>> Matrix)
    {
        // code here
        int dp[n][n];
        for(int i=0;i<n;i++){
            dp[n-1][i]=Matrix[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<n;j++){
                int a=0;
                int b=0;
                int c=0;
                a=dp[i+1][j];
                if(((j-1)>=0)){
                    b=dp[i+1][j-1];
                    
                }
                if((j+1)<n){
                    c=dp[i+1][j+1];
                }
                int val=max(a,max(b,c));
                dp[i][j]=Matrix[i][j]+val;
            }
        }
        int maxm=0;
        for(int i=0;i<n;i++){
            maxm=max(maxm,dp[0][i]);
            
            
        }
        return maxm;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends