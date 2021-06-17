// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int xo=0;
        for(int i=0;i<nums.size();i++){
            xo=xo^nums[i];
            
        }
        int bit_mask=xo & (-xo);
        int x=0;
        int y=0;
        for(int i=0;i<nums.size();i++){
            if((nums[i]&bit_mask)){
                x=x^nums[i];
            }else{
                y=y^nums[i];
            }
        }
        vector<int>ans;
        ans.push_back(min(x,y));
        ans.push_back(max(x,y));
        return ans;
    }
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}  // } Driver Code Ends