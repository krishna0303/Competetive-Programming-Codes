// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    
    // 1st method we can use backtracking but time complexity will be 2^n
    
    //2nd method TC-O(n^2)
    
    // int longestSubsequence(int n, int arr[])
    // {
    //   int dp[n];
       
    //   for(int i=0;i<n;i++){
    //       dp[i]=1;
           
           
    //   }
    //   int max_value=1;
    //   int i=1;
    //   int j=1;
    //   while(i<n){
    //       for(int j=0;j<i;j++){
    //           if(arr[j]<arr[i]&&dp[i]<=dp[j]){
    //               dp[i]=1+dp[j];
    //       }
           
    //       }
    //       max_value=max(max_value,dp[i]);
    //       i++;
           
           
    //   }
    //   return max_value;
       
       
       
       
    // }
    //3rd method TC - O(nlogn) watch code library video
    int longestSubsequence(int n, int arr[])
    {
       int dp[n+1];
       
       for(int i=0;i<=n;i++){
           dp[i]=INT_MAX;
           
           
       }
       dp[0]=INT_MIN;
       for(int i=0;i<n;i++){
           int idx=upper_bound(dp,dp+n+1,arr[i])-dp;
           if(dp[idx-1]<arr[i]&&dp[idx]>arr[i]){
               dp[idx]=arr[i];
           }
       }
       for(int i=n;i>=0;i--){
           if(dp[i]!=INT_MAX){
               return i;
           }
       }
       
       
       
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends