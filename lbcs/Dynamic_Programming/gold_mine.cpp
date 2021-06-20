#include<bits/stdc++.h>
using namespace std;

//for better understanding watch code librarry video

int GoldminProblem(int**dp,int n,int m){
    for(int i=m-2;i>=0;i--){
        for(int j=0;j<n;j++){
            int a=0;
            int b=0;
            int c=0;
            if(j-1>=0){
                a=dp[j-1][i+1];
            }
            b=dp[j][i+1];
            if(j+1<n){
                c=dp[j+1][i+1];
            }
            
            dp[j][i]+=max(a,max(b,c));
        }
    }
    int val=INT_MIN;
    for(int i=0;i<n;i++){
        val=max(val,dp[i][0]);

    }
    return val;

}

int main(){
    int n,m;
    cin>>n>>m;
    int **dp=new int*[n];
    for(int i=0;i<n;i++){
        dp[i]=new int[m];
        for(int j=0;j<m;j++){
            cin>>dp[i][j];
        }
    }

    cout<<GoldminProblem(dp,n,m)<<endl;

    
        
    
    return 0;
}