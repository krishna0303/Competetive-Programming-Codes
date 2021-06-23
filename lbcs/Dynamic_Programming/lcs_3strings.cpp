// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends
/*

The idea is to take a 3D array to store the 
length of common subsequence in all 3 given 
sequences i. e., L[m + 1][n + 1][o + 1]

1- If any of the string is empty then there
   is no common subsequence at all then
           L[i][j][k] = 0

2- If the characters of all sequences match
   (or X[i] == Y[j] ==Z[k]) then
        L[i][j][k] = 1 + L[i-1][j-1][k-1]

3- If the characters of both sequences do 
   not match (or X[i] != Y[j] || X[i] != Z[k] 
   || Y[j] !=Z[k]) then
        L[i][j][k] = max(L[i-1][j][k], 
                         L[i][j-1][k], 
                         L[i][j][k-1])



*/

int lcs(int x, int y,int z, string s1, string s2,string s3)
    {

        int ***dp=new int**[x+1];
        for(int i=0;i<=x;i++){
            dp[i]=new int*[y+1];
            for(int j=0;j<=y;j++){
                dp[i][j]=new int[z+1];
            }
            
        }
       
        
        
        for(int i=0;i<=x;i++){
           
            for(int j=0;j<=y;j++){
                for(int k=0;k<=z;k++){
                     if (i == 0 || j == 0||k==0)
                    dp[i][j][k] = 0;
                    
                    else if(s1[i-1]==s2[j-1]&&s1[i-1]==s3[k-1]){
                        dp[i][j][k]=1+dp[i-1][j-1][k-1];
                        
                        
                    }
                    
                    else{
                        dp[i][j][k]=max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
                            
                        }
                    
                }
                
 
             
                
            }
            
            
            
        }
        return dp[x][y][z];
    }
int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    // your code here
    return lcs(n1,n2,n3,A,B,C);
    
    
}