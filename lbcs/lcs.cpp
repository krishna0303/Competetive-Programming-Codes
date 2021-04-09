// longest common subsequence in 2 strings

#include<bits/stdc++.h>
using namespace std;
int LongestRepeatingSubsequence(string s1,string s2){
    int n=s1.length();
    int m=s2.length();
    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++){
    dp[i]=new int[m+1];
    }
    // string s2=s;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            
                dp[i][j]=0;
            
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            
          if(s1[i-1]==s2[j-1]){
              
                    dp[i][j]=1+(dp[i-1][j-1]);
                
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];

		
}

string printRepeatingSubsequences(string s1,string s2){
    int n=s1.length();
    int m=s2.length();

    string **dp=new string*[n+1];
    for(int i=0;i<=n;i++){
    dp[i]=new string[m+1];
    }
    // string s2=s;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            
                dp[i][j]="";
            
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            
          if(s1[i-1]==s2[j-1]){
              
                    dp[i][j]=(dp[i-1][j-1])+s1[i-1];
                
            }else{
               if(dp[i-1][j].length()>dp[i][j-1].length()){
                   dp[i][j]=dp[i-1][j];
               }else{
                   dp[i][j]=dp[i][j-1];

               }
            }
        }
    }
    return dp[n][m];
}


int main(){
    string s1,s2;
    cin>>s1>>s2;
    int ans=LongestRepeatingSubsequence(s1,s2);
    string ans1=printRepeatingSubsequences(s1,s2);
    cout<<ans<<endl;
    cout<<ans1<<endl;



    return 0;
}