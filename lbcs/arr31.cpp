#include<bits/stdc++.h>
using namespace std;

void getProfit2(int *arr, int n){
   int dp[n];
   for(int i=0;i<n;i++)dp[i]=0;
   int ma=arr[n-1];
   int mi=arr[0];
   for(int i=n-2;i>=0;i--){
       if(arr[i]>ma){
           ma=arr[i];
           
       }
       dp[i]=max(dp[i+1],ma-arr[i]);

   }
   for(int i=1;i<n;i++){
       if(arr[i]<mi){
           mi=arr[i];
           
       }
       dp[i]=max(dp[i-1],dp[i]+(arr[i]-mi));

   }
   for(int i=0;i<n;i++){
       cout<<dp[i]<<" ";
   }
   cout<<endl;
   cout<<dp[n-1]<<endl;

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    getProfit2(arr, n);
    



    return 0;
}