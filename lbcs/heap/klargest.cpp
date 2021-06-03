// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++


/*
using heap stl

vector<int> kLargest(int arr[], int n, int k) {
	    // code here
	    vector<int>v1;
	    for(int i=0;i<n;i++){
	        v1.push_back(arr[i]);
	    }
	   make_heap(v1.begin(), v1.end());
	    vector<int>ans;
	    for(int i=0;i<k;i++){
	        ans.push_back(v1.front());
	        pop_heap(v1.begin(), v1.end());
            v1.pop_back();
	    }
	    return ans;
	    
	    
	}



*/

void heapify(int arr[],int n,int i){
    int l=2*i+1;
    int r=2*i+2;
    int max=i;
    if(l<n&&arr[l]>arr[i]){
        max=l;
    }
    if(r<n&&arr[r]>arr[max]){
        max=r;
    }
    if(max!=i){
        swap(arr[i],arr[max]);
        heapify(arr,n,max);
    }
}

void buildHeap(int arr[],int n){
    for(int i=(n/2-1);i>=0;i--){
        heapify(arr,n,i);
    }
}

class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    // code here
	    buildHeap(arr,n);
	    vector<int>ans;
	    int count=0;
	    for(int i=n-1;i>0;i--){
	        if(count==k){
	            break;
	        }
	        count+=1;
	        
	        ans.push_back(arr[0]);
	        swap(arr[0],arr[i]);
	        heapify(arr,i,0);
	        
	        
	        
	    }
	    return ans;
	    
	    
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends