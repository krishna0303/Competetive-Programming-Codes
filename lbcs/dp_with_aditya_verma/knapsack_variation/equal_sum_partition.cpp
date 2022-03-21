// there is only little variation with subset sum problem
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


class Solution{
public:
    
    int subsetSum(int n,int arr[],int sum,int **dp){
        if(sum==0){
            return 1;
        }
        if(n==0&&sum!=0){
            return 0;
        }
        if(dp[n][sum]!=-1){
            return dp[n][sum];
        }
        if(arr[n-1]<=sum){
            return dp[n][sum]=(subsetSum(n-1,arr,sum-arr[n-1],dp)||subsetSum(n-1,arr,sum,dp));
        }else{
            return dp[n][sum]=subsetSum(n-1,arr,sum,dp);
        }
    }
    int equalPartition(int n, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        if(sum%2!=0){
            return 0;
        }else{
            sum=sum/2;
            int **dp=new int*[n+1];
            for(int i=0;i<=n;i++){
                dp[i]=new int[sum+1];
                for(int j=0;j<=sum;j++){
                    dp[i][j]=-1;
                }
            }
            return subsetSum(n,arr,sum,dp);
            
        }
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code End