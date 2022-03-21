// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int t[201][201];
    int solve(int e,int f){
        if(e == 1 or f == 0 or f == 1){
            return f;
        }
        if(t[e][f] != -1){
            return t[e][f];
        }
        int ans = INT_MAX;
        for(int i=1;i<=f;i++){
            // int temp = 1 + max(solve(e-1,i-1),solve(e,f-i));
            int low=INT_MIN,high=INT_MIN;
            if(t[e-1][i-1]!=-1){
                low=t[e-1][i-1];
            }else{
                low=solve(e-1,i-1);
                t[e-1][i-1]=low;
            }
            if(t[e][f-i]!=-1){
                high=t[e][f-i];
            }else{
                high=solve(e,f-i);
                t[e][f-i]=high;
            }
            int temp=1+max(low,high);
            ans = min(ans,temp);
        }
        return t[e][f] = ans;
    }
    int eggDrop(int n, int k){
        memset(t,-1,sizeof t);
        solve(n,k);
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