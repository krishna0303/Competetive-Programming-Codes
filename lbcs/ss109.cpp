// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        sort(arr.begin(),arr.end());
        int previous=INT_MIN;
        vector<vector<int>>ans;
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n-3;i++){
            // if(arr[i]!=arr[i-1]){
                
            
            sum=arr[i];
            for(int j=i+1;j<n-2;j++){
                // if(arr[j]==arr[j-1]){
                //     continue;
                // }
                sum+=arr[j];
                if(previous==sum){
                    continue;
                    
                }
                previous=sum;
                    
                
                
                int low=j+1,high=n-1;
                while(low<high){
                    
                    if((arr[low-1]!=arr[low]||arr[high+1]!=arr[high])&&((sum+arr[low]+arr[high])==k)){
                        vector<int>v;
                        v.push_back(arr[i]);
                        v.push_back(arr[j]);
                        v.push_back(arr[low]);
                        v.push_back(arr[high]);
                        ans.push_back(v);
                        
                        low++;
                        high--;
                        
                    }else if((sum+arr[low]+arr[high])<k){
                        low++;
                        
                    }else{
                        high--;
                    }
                    
                    
                }
                sum=arr[i];
                
                
                
            }
            // }
        }
        // }
        return ans;
    
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends