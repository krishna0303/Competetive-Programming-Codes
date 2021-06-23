#include<bits/stdc++.h>
using namespace std;
int ProductlessthanK(int *arr,int n,int k){
    int dp[k+1][n+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=dp[i][j-1];
            //this condition is for counting number of subsequences formed by including j-1 th element and it to the previous count 
            if(arr[j-1]<=i){
                dp[i][j]+=(dp[i/arr[j-1]][j-1]+1);  //it will go (i/arr[j-1])th row and it will try to get the how many previous subsequnces availble where i can insert this j-1th value and having product less than k
                //let take an example i=4,arr[j-1]=2 4/2==2 so it will count all the subsequnces which having product less than 2 and add it to the result count
                //becase if we insert this j-1th value to form new subsequences by inserting current element it 
                //basically it shows how many extra subsequences formed by including this current value
                // and here +1 is indicating that current value individuall i.e j-1 th value is 4 then 4 is alone a subsequence if it is less than k
            }
        }
    }
    return dp[k][n];
}
int main(){
    int n,k;
    cin>>n>>k;

    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<ProductlessthanK(arr,n,k)<<endl;
    return 0;
}