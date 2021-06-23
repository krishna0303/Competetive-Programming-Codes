// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        
        // Your code here  
       /*

        generally we can find direclty if anyu number is power of two or not by n&(n-1) here n will be that number n-1 will be one smaller than number
        let's take an example n=4 then n-1 will become 3 so 100&011 if it will come 0 then it means the number is power of two otherwise not
        but if n==0 then we have to use below condition to handle this one i.e (n&&(!(n&(n-1))))
        we can also use this to handle 0
         if(n==0){
            return false;
        }
        return (!(n&(n-1)));
       */
        return (n&&(!(n&(n-1))));     
        
        
        
    }
};

// { Driver Code Starts.

// Driver code
int main()
{

    int t;
    cin>>t;//testcases

    for(int i=0;i<t;i++)
    {
        long long n; //input a number n
        cin>>n;

        Solution ob;
         if(ob.isPowerofTwo(n))//Now, if log2 produces an integer not decimal then we are sure raising 2 to this value
             cout<<"YES"<<endl;
         else
            cout<<"NO"<<endl;

    }

    return 0;
}
  // } Driver Code Ends