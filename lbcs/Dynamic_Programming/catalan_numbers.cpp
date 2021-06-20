// { Driver Code Starts
// Initial Template for C++
//For better use follow geek for geeks link

#include <bits/stdc++.h>
using namespace std;

int dp[10000];

int CatalanNumber(int n){
    if(n<=1){
        dp[n]=1;
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    
    int val=0;
    for(int i=0;i<n;i++){
        val+=CatalanNumber(i)*CatalanNumber(n-i-1);
    }
    return dp[n]=val;
    
}
// int CatalanNumber(int n){
//     int dp[n+1];
//     dp[0]=1;
//     dp[1]=1;
//     for(int i=2;i<=n;i++){
//         for(int j=0;j<i;j++){
//             dp[i]+=(dp[j] * dp[i-j-1]);
//         }
//     }
//     for(int i=0;i<=n;i++){
//         cout<<dp[i]<<" ";
//     }
//     cout<<endl;
//     return dp[n];
    
// }
int main(){
    int n;
    cin>>n;
    dp[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=-1;
    }
    cout<<CatalanNumber(n)<<endl;
    return 0;
}  // } Driver Code Ends