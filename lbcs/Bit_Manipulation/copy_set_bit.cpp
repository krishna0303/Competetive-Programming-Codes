// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:

    int copySetBits(int x,int y,int l,int r)
    {
        y=y>>l;  //this because of to move y to the first pointer i.e lth position of y then we can iterate one by one
        
        for(int i=l;i<=r;i++){
            if(y&1){
                int val=1<<(i);
                x=x|val;

            }
                y=y>>1;

            

        }
        return x;
        
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
	       int x,y,l,r;
	       cin>>x>>y>>l>>r; //input n
	       Solution ob;
	       cout << ob.copySetBits(x,y,l-1,r-1) << endl;// print the answer
	  }
	  return 0;
}
  // } Driver Code Ends