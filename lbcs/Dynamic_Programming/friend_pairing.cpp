// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    // long long int dp[1000001];
    //recursive
    //p(n)=p(n-1)+(n-1)*p(n-2);
    /*
    f(n) = ways n people can remain single 
       or pair up.

For n-th person there are two choices:
1) n-th person remains single, we recur 
   for f(n - 1)
2) n-th person pairs up with any of the 
   remaining n - 1 persons. We get (n - 1) * f(n - 2)

Therefore we can recursively write f(n) as:
f(n) = f(n - 1) + (n - 1) * f(n - 2)
    
    */
    const long long mod=1000000007;
    int countFriendsPairings1(int n,long long int dp[]) 
    { 
        // code here
        if(dp[n]!=-1){
            return dp[n]%mod;
        }
        if(n<=2){
           
            return  dp[n]=n%mod;
        }
        else{
           return dp[n]=(countFriendsPairings1(n-1,dp)%mod+((((n-1)%mod)*countFriendsPairings1(n-2,dp)%mod)%mod)%mod)%mod;
        //   return dp[n]%mod;
        }
    }
    int countFriendsPairings(int n) 
    { 
        // code here
        long long int dp[n+1];
        for(long long int i=0;i<=n;i++){
            dp[i]=-1;
        }
        
        return countFriendsPairings1(n,dp)%mod;
    }
};

// bottom up approach iterative method
//  int countFriendsPairings(int n) 
//     { 
//         // code here
//         long long int dp[n+1];
//         for(int i=0;i<=n;i++){
//             if(i<=2){
//                 dp[i]=i;
//             }else{
                
//                 dp[i]=(dp[i-1]%mod+(i-1)%mod*dp[i-2]%mod)%mod;
//             }
//         }
        
//         return dp[n]%mod;
//     }
 

// { Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 
  // } Driver Code Ends