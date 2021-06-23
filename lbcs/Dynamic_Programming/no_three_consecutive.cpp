#include<bits/stdc++.h>
using namespace std;
int MaxSumSubSequences(int *arr,int n){
    int dp[n];
    if(n>=1){
         dp[0]=arr[0];
    }
    if(n>=2){
        dp[1]=arr[0]+arr[1];

    }
    
    
    if(n>2){
        dp[2]=max(dp[1],max(arr[1]+arr[2],arr[0]+arr[2]));

    }
    
    
    for(int i=3;i<n;i++){
        dp[i]=max(dp[i-1],max(dp[i-2]+arr[i],dp[i-3]+arr[i-1]+arr[i]));

    }
    return dp[n-1];
    
}
int main(){
    int n;
    cin>>n;

    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<MaxSumSubSequences(arr,n)<<endl;
    return 0;
}