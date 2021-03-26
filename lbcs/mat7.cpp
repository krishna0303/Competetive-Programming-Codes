//Given an n x n matrix mat[n][n] of integers, 
// find the maximum value of mat(c, d) – mat(a, b) over all choices of indexes such that both c > a and d > b.
// Input:
// mat[N][N] = {{ 1, 2, -1, -4, -20 },
//              { -8, -3, 4, 2, 1 }, 
//              { 3, 8, 6, 1, 3 },
//              { -4, -1, 1, 7, -6 },
//              { 0, -4, 10, -5, 1 }};
// Output: 18
// The maximum value is 18 as mat[4][2] 
// - mat[1][0] = 18 has maximum difference. 


#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int **arr=new int*[n];
    for(int i=0;i<n;i++){
        arr[i]=new int[n];
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    int dp[n][n];
    int maxValue=INT_MIN;
    
    int maxv=arr[n-1][n-1];
    dp[n-1][n-1]=maxv;
    for(int j=n-2;j>=0;j--){
        if(arr[n-1][j]>maxv){
            maxv=arr[n-1][j];

        }
        dp[n-1][j]=maxv;
    }
    maxv=arr[n-1][n-1];
    for(int i=n-2;i>=0;i--){
        if(arr[i][n-1]>maxv){
            maxv=arr[i][n-1];

        }
        dp[i][n-1]=maxv;
    }

    for(int i=n-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            if(dp[i+1][j+1]-arr[i][j]>maxValue){
                maxValue=dp[i+1][j+1]-arr[i][j];
            }
            dp[i][j]=max(arr[i][j],max(dp[i+1][j],dp[i][j+1]));
        }
    }

    cout<<maxValue<<endl;



    return 0;
}