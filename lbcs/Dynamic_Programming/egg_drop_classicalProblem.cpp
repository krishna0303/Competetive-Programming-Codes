// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// for better understanding iof this problem and approach watch sumeet malik https://www.youtube.com/watch?v=UvksR0hR9nA video


class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        
        int dp[n+1][k+1];
        for(int i=0;i<=n;i++){
            dp[i][0]=0;  //if floor zero then attemps for any eggs is 0
            dp[i][1]=1;//if floor one availbel then attempts for any number of eggs are 1
            
        }
        for(int i=0;i<=k;i++){
            dp[0][i]=0;    //egg zero then zero attempts for any number of floors
            dp[1][i]=i;    //if egg 1 then in worst case the attempt would be total number of floors availble at that time
            
        }
        for(int i=2;i<=n;i++){
            for(int j=2;j<=k;j++){
                //here we are trying to find the besgt of considering worst case for a ith egg and jth floor
                int val=INT_MAX;
                for(int x=0;x<j;x++){    
                    val=min(val,max(dp[i-1][x],dp[i][j-x-1]));   //dp[i-1][x]-eggs break and dp[i][j-x-1] -eggs save and we have to minimize the worst case i.e max of these attempts
                    
                    
                }
                dp[i][j]=val+1;  //we are adding 1 because we have use 1 attempt to check whetehr ith eggs is break or save on jth floor but we have uses 1 attemps to chekck this conditions
                
            }
        }
        return dp[n][k];
        // 
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends