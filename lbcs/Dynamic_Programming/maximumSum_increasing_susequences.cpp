// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:

    /*

    dry run this case
    For Input:
    5
    78 1 79 2 3
    your output is: 
    157
    This problem is a variation of standard Longest Increasing Subsequence (LIS) problem. We need a slight change in the Dynamic Programming solution of LIS problem. 
    All we need to change is to use sum as a criteria instead of length of increasing subsequence.
    
    */
	int maxSumIS(int arr[], int n)  
	{  
	    int dp[n];
	    for(int i=0;i<n;i++){
	        dp[i]=arr[i];
	    }
	    int i=1;
	   
	    

	    while(i<n){

	        for(int j=0;j<i;j++){
	            if(arr[i]>arr[j]&&dp[i]<dp[j]+arr[i]){
	               // count+=arr[j];
	               // st+=1;
	                dp[i]=dp[j]+arr[i];
	        }
	        
	            
	        }
	   
	        i++;
	        
	    }
	    
	   
	    int lis=0;
	    for(int i=0;i<n;i++){
	        if(lis<dp[i]){
	            lis=dp[i];
	            
	        }
	        
	        
	    }
	    return lis;
	   
	    
	}  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends