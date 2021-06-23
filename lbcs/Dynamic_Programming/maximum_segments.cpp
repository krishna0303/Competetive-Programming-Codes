// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends



class Solution
{
    public:
    //Function to find the maximum number of cuts.
    
    int maximizeTheCuts1(int n, int x, int y, int z,int dp[])
    {
        //Your code here
        if(n<0){
            return -1;
        }
        if(n==0){
            return dp[n]=0;
        }
        if(dp[n]!=-2){
            return dp[n];
        }
        int a=1+maximizeTheCuts1(n-x,x,y,z,dp);
        int b=1+maximizeTheCuts1(n-y,x,y,z,dp);
        int c=1+maximizeTheCuts1(n-z,x,y,z,dp);
        int maxm=max(a,max(b,c));
        if(maxm==0){ //this condtion comes when a=0 b=0 and c=0 and above three function will return -1 eg 1(n) 2 5 5 (x, y, z) so in this case if we subtract we will get n<0 so it will return -1 for three variable x y and z
            dp[n]=-1;
            return -1;
        }else{
            dp[n]=maxm;
            return dp[n];
        }
       
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
       int dp[n+1];
       for(int i=0;i<=n;i++){
           dp[i]=-2;   //assigning -2 because i'm storing -1 as a value in dp
       }
       int val=maximizeTheCuts1(n,x,y,z,dp);
       if(val==-1){     //if cut is not possible then return 0 because above fucntion will return -1 in this case
           return 0;
       }
       return val ;
    }
    
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends