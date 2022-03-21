// { Driver Code Starts
// Initial Template for c++

/*
Given a string str, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome. 
Determine the fewest cuts needed for palindrome partitioning of given string.


Example 1:

Input: str = "ababbbabbababa"
Output: 3
Explaination: After 3 partitioning substrings 
are "a", "babbbab", "b", "ababa".

*/

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[501][501];
    
    bool isPalindrome(string str,int i,int j){
        if(i>j){
            return false;
        }
        if(i==j){
            return true;
        }
        while(i<j){
            if(str[i]!=str[j]){
                return false;
            }
                i++;
                j--;
           
        }
        return true;
    }
    int solve(string str,int i,int j){
        if(i>=j){
            return 0;
        }
        if(isPalindrome(str,i,j)){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int mn=INT_MAX;
        for(int k=i;k<j;k++){
            int left=0;
            int right=0;
            if(dp[i][k]!=-1){
                left=dp[i][k];
            }else{
                left=solve(str,i,k);
            }
            if(dp[k+1][j]!=-1){
                right=dp[k+1][j];
            }else{
                right=solve(str,k+1,j);
            }
            int temp=1+left+right;
            if(temp<mn){
                mn=temp;
            }
        }
        return dp[i][j]=mn;
    }
    int palindromicPartition(string str)
    {
        memset(dp,-1,sizeof(dp));
        return solve(str,0,str.length()-1);
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends