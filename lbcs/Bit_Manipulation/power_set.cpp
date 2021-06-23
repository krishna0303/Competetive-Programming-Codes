// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
    /*
    Input: Set[], set_size
1. Get the size of power set
    powet_set_size = pow(2, set_size)
2  Loop for counter from 0 to pow_set_size
     (a) Loop for i = 0 to set_size
          (i) If ith bit in counter is set
               Print ith element from set for this subset
     (b) Print separator for subsets i.e., newline
    
    */
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string>v;
		    int n=s.length();
		    for(int i=1;i<pow(2,n);i++){
		        string temp="";
		        int x=i;
		        for(int j=0;j<n;j++){
		            if(x&1){
		                temp+=s[j];
		            }
		            x=x>>1;
		           
		            
		        }
		        v.push_back(temp);
		        
		    }
		    sort(v.begin(),v.end());
		    return v;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends