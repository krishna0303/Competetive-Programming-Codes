/*
edit distance
*/

#include<bits/stdc++.h>
using namespace std;

int editDistance(string s1, string s2){
    int n=s1.length();
    int m=s2.length();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0){
                dp[i][j]=j;
            }else if(j==0){
                dp[i][j]=i;
            }
            else if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }else{
                dp[i][j]=1+min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
            }
        }
    }
    return dp[n][m];
}
int main(){

    string s,s2;
    cin>>s>>s2;
    int ans=editDistance(s,s2);
    cout<<ans<<endl;



    return 0;

}
