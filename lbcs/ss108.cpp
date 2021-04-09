// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
         sort(a,a+size);
    int maj=-1;
    int count=1;
    int maxcount=INT_MIN;
    for(int i=1;i<size;i++){
        if(a[i]==a[i-1]){
            count+=1;
        }else{
            // cout<<count<<endl;
            if(count>maxcount&&count>size/2){
                maj=a[i-1];
            }
            maxcount=count;
            count=1;
        }
        
        
    }
    if(count>maxcount&&count>size/2){
        // cout<<count<<endl;
                maj=a[size-1];
                count=1;
            }
    return maj;    
        // your code here
        
    }
    // Moore majority voting algorithm

int Majority(int a[],int n){
    int max_index=0;
    int count=1;
    for(int i=1;i<n;i++){
        if(a[max_index]==a[i]){
            count++;
        }else{
            count--;
        }
        if(count==0){
            max_index=i;
            count=1;
        }
    }
    return a[max_index];
}

bool isMajor(int a[],int n,int cand){
    int count=0;
    for(int i=0;i<n;i++){
        if(a[i]==cand){
            count++;
        }

    }
    if(count>n/2){
        return true;
    }else{
        return false;
    }

}

int majorityElement2(int a[],int n){
    int ans=-1;
    int cand=Majority(a,n);
    if(isMajor(a,n,cand)){
        return cand;
    }else{
        return -1;
    }
}
};






// { Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement2(arr, n) << endl;
    }

    return 0;
}
  // } Driver Code Ends