// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++
/*

ida is to right shift both number one by one and take and with 1 if both elemnt produces the same result it means 
the corresponding bits are same hence we not have to modify or count that if dirrent value occurs then we have to count it
*/

class Solution{
    public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){
        
        
        int count=0;
        for(int i=0;i<32;i++){
            int x1=(a&1);
            int x2=(b&1);
            if(x1!=x2){
                count+=1;
                
            }
            a=a>>1;
            b=b>>1;
        }
        return count;
        
    }
};

// { Driver Code Starts.

// Driver Code
int main()
{
	int t;
	cin>>t;// input the testcases
	while(t--) //while testcases exist
	{
		int a,b;
		cin>>a>>b; //input a and b

        Solution ob;
		cout<<ob.countBitsFlip(a, b)<<endl;
	}
	return 0;
}  // } Driver Code Ends