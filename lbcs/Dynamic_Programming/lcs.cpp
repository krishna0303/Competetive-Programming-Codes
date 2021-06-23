// { Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.

    //recursive solution
    
    // int lcsUtil(int x, int y, string s1, string s2,int**dp)
    // {
    //     // your code here
    //     if(x==0||y==0){
    //         return 0;
    //     }
    //     if(dp[x][y]!=-1){
    //         return dp[x][y];
    //     }
    //     if(s1[x-1]==s2[y-1]){
    //         return dp[x][y]=1+lcsUtil(x-1,y-1,s1,s2,dp);
    //     }else{
    //         return dp[x][y]=max(lcsUtil(x-1,y,s1,s2,dp),lcsUtil(x,y-1,s1,s2,dp));
    //     }
    // }
    // int lcs(int x, int y, string s1, string s2)
    // {
    //     // your code here
    //     int **dp=new int*[x+1];
    //     for(int i=0;i<=x;i++){
    //         dp[i]=new int[y+1];
    //         for(int j=0;j<=y;j++){
    //             dp[i][j]=-1;
                
    //         }
    //     }
    //     int val=lcsUtil(x,y,s1,s2,dp);
        
        
    //     return val;
    // }

    //Iterative solution
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        int **dp=new int*[x+1];
        for(int i=0;i<=x;i++){
            dp[i]=new int[y+1];
            for(int j=0;j<=y;j++){
                dp[i][j]=-1;
                
            }
        }
        for(int i=0;i<=x;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<=y;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                if(s1[i-1]!=s2[j-1]){
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                    
                }
                else{
                        dp[i][j]=1+dp[i-1][j-1];
                    }
                
            }
        }
        return dp[x][y];
    }
    /*

    //space optimized solution
    here we only need 2 rows and y columns
    
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        int **dp=new int*[2];
        for(int i=0;i<2;i++){
            dp[i]=new int[y+1];
            
        }
        for(int i=0;i<2;i++){
            dp[i][0]=0;
            
        }
        for(int i=0;i<=y;i++){
            dp[0][i]=0;
            
        }
        int count=1; this is used for string iteration because here i value only be either 0 or 1 but we have to iterate over first string so this count is helpful for that task
        
        
        for(int i=1;count<=x;){
           
            for(int j=1;j<=y;j++){
                
 
             if(s1[count-1]!=s2[j-1]){  here we are checking by using count not i because i is either 0 or 1
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                    
                }
                else{
                        dp[i][j]=1+dp[i-1][j-1];
                    }
                
            }
            this for loop is used for to assign the 1st row value to the 0th row value after calculation of 1st row value
            because we only need two row here so this task is imp so that we can caluculate for next value
            for(int j=1;j<=y;j++){
                
 
                dp[i-1][j]=dp[i][j];
                
            }
            i=1;  again intialize i by 1
            count+=1;  increament count for first string
            
            
        }
        return dp[1][y]; this is the last cell of dp[1][y] array which has maximum lcs
    }
    
    
    */
};


// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
  // } Driver Code Ends