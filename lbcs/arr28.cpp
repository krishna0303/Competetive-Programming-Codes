#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int maxPro=0;
    
    int minM=1;
    int maxM=1;
    for(int i=0;i<n;i++){
        if(arr[i]>0){
            maxM=maxM*arr[i];
            minM=min(minM*arr[i],1);
        }else if(arr[i]<0){
            int temp=maxM;
            maxM=max(minM*arr[i],1);
            minM=temp*arr[i];


        }else{
            minM=1;
            maxM=1;
        }
        if(maxPro>maxM){
            maxPro=maxM;
        }
    }




    return 0;
}

//Geeks For Geeks code

/*
// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(int *arr, int n) {
	    
	    long long maxPro=0;
    
    long long  minM=1;
    long long  maxM=1;
    // bool flag=0;
    
    for(int i=0;i<n;i++){
        if(arr[i]>0){
            maxM=maxM*arr[i];
            minM=min(minM * arr[i],(long long)1);
            // flag=1;
        }else if(arr[i]<0){
            long long temp=maxM;
            maxM=max(minM*arr[i],(long long)1);
            minM=temp*arr[i];


        }else{
            minM=1;
            maxM=1;
        }
        if(maxPro<maxM){
            maxPro=maxM;
        }
    }
    // if (flag == 0 && maxPro == 0)
    //     return 0;
    
    return maxPro;
	    // code here
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
*/
