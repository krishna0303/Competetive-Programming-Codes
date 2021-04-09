// Given a string str, find length of the longest repeating subseequence such that the two subsequence don’t
//  have same string character at same position, i.e.,
//  any i’th character in the two subsequences shouldn’t have the same index in the original string.

#include<bits/stdc++.h>
using namespace std;
int LongestRepeatingSubsequence(string s){
    int n=s.length();
    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++){
    dp[i]=new int[n+1];
    }
    string s2=s;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            
                dp[i][j]=0;
            
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            
          if(s[i-1]==s[j-1]&&i!=j){
              
                    dp[i][j]=1+(dp[i-1][j-1]);
                
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][n];

		
}

string printRepeatingSubsequences(string s){
    int n=s.length();
    string **dp=new string*[n+1];
    for(int i=0;i<=n;i++){
    dp[i]=new string[n+1];
    }
    string s2=s;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            
                dp[i][j]="";
            
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            
          if(s[i-1]==s[j-1]&&i!=j){
              
                    dp[i][j]=(dp[i-1][j-1])+s[i-1];
                
            }else{
               if(dp[i-1][j].length()>dp[i][j-1].length()){
                   dp[i][j]=dp[i-1][j];
               }else{
                   dp[i][j]=dp[i][j-1];

               }
            }
        }
    }
    return dp[n][n];
}


int main(){
    string s;
    cin>>s;
    int ans=LongestRepeatingSubsequence(s);
    string ans1=printRepeatingSubsequences(s);
    cout<<ans<<endl;
    cout<<ans1<<endl;



    return 0;
}