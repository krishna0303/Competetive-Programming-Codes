// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
    /*
    n*n=n*(10101)=n*2^4+n*2^2+n*2^0
   */
		int SquareOfIntegers(int n){
            int res=0;
            int temp=n;
            for(int i=0;i<32;i++){
                if(temp&1){
                    res+=(n<<i);
                }
                temp=temp>>1;
            }
            return res;

		    
		   
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		cout<<ob.SquareOfIntegers(n)<<endl;
		

	}
	return 0;
}  // } Driver Code Ends