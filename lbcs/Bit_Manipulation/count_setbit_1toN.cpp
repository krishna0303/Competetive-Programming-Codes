// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int powerOftwo(int n){
        int x=0;
        while(1<<x<=n){  //2^0=1<=n
                         //2^1=2<=n similarly it will go till while loop condition satisfies
            x++;
        }
        return x-1;
        
        
    }
    int countSetBits(int n)
    {
        // Your logic here
        if(n==0){
            return 0;
        }
        int x=powerOftwo(n);
        int bitlessthanx=x*(1<<(x-1));//(x*2^(x-1))
        int msbbits=n-(1<<x)+1;
        int rest=n-(1<<x);
        
       
        return bitlessthanx+msbbits+countSetBits(rest);
    }
};


// { Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}
  // } Driver Code Ends