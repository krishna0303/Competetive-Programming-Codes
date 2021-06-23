// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++


//to undersxtand this refer this video https://www.youtube.com/watch?v=bdxJHWIyyqI

class Solution{
    public:

    int copySetBits(int dividend,int divisor)
    {
        int sign=(dividend<0)^(divisor<0)?-1:1;   //it is used to handle negative or positive sign of the number and ^operator is used to handle if both are positve or both are negative then answer would be positive
        dividend=abs(dividend); //to remove sign of numbers
        divisor=abs(divisor);//same
        int n=dividend;
        int m=divisor;
        long long q=0,temp=0;   //q store quotient and temp store temporary value
        for(int i=31;i>=0;i--){  //we are iterating here loop from higher i.e msb to lsb because we want to find out maximum number of bits wjioch the below condition
            if((temp+m<<i)<=n){    //temp+m*pow(2,i)<=n or not if less than 
                temp+=m<<i;   //add this value to temp
                q=q|(1LL<<i);   //here 1ll is used only because type of q is long long otherwise it is basically a 1<<i which set that bit which hold above condition that would be our final answer or quotient
            }
        }
        if(sign<0){
            q=-q;
        }
        return q;
        //to understand this question better to dry run above code with example for 
        // n=10,m=3
        // n=40,m=-5
        // n=-40,m=-5

        
        
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
	       int x,y;
	       cin>>x>>y; //input n
	       Solution ob;
	       cout << ob.copySetBits(x,y) << endl;// print the answer
	  }
	  return 0;
}
  // } Driver Code Ends