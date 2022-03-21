// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    // int dp[102][100002];

    // int isSubsetSumUtil(int n, int arr[], int sum,int**dp){
    //     if(sum==0){
    //         return dp[n][sum]=1;
    //     }
    //     if(n==0&&sum!=0){
    //         return dp[n][sum]=0;
    //     }
    //     if(dp[n][sum]!=-1){
    //         return dp[n][sum];
    //     }
    //     if(arr[n-1]<=sum){
    //         bool ans1=isSubsetSumUtil(n-1,arr,sum-arr[n-1],dp);
    //         bool ans2=isSubsetSumUtil(n-1,arr,sum,dp);
    //         if(ans1||ans2){
    //             return dp[n][sum]=1;
    //         }else{
    //             return dp[n][sum]=0;
    //         }
    //         // return dp[n][sum]=(is)

    //     }
    //     else if(arr[n-1]>sum){
    //         return dp[n][sum]=isSubsetSumUtil(n-1,arr,sum,dp);

    //     }

    // }
    // bool isSubsetSum(int n, int arr[], int sum){
    //     // code here
    //     // memset(dp,-1,sizeof(dp));
    //     // for(int i=0;i<102;i++){
    //     //     for(int j=0;j<100002;j++){
    //     //         dp[i][j]=-1;
    //     //     }
    //     // }
    //     int **dp=new int*[n+1];
    //     for(int i=0;i<n+1;i++){
    //         dp[i]=new int[sum+1];
    //         for(int j=0;j<=sum;j++){
    //             dp[i][j]=-1;
    //         }
    //     }
    //     if(isSubsetSumUtil(n,arr,sum,dp)==1){
    //         return true;
    //     }else{
    //         return false;
    //     }

    // }
    bool isSubsetSum(int n, int arr[], int sum)
    {

        bool dp[n + 1][sum + 1];
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < sum + 1; j++)
            {
                if (i == 0)
                {
                    dp[i][j] = false;
                }
                if (j == 0)
                {
                    dp[i][j] = true;
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                if (arr[i - 1] <= j)
                {
                    dp[i][j] = (dp[i - 1][j - arr[i - 1]]) || (dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][sum];
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, sum;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        cin >> sum;

        Solution ob;
        cout << ob.isSubsetSum(N, arr, sum) << endl;
    }
    return 0;
}
// } Driver Code Ends