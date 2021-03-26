// An array contains both positive and negative numbers in random order.
//  Rearrange the array elements so that all negative numbers appear before all positive numbers.

// 1 Quick Sort Approach
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int *arr= new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int j=0;
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            if(i!=j){
                swap(arr[i],arr[j]);
            }
            j++;
        }

        
    }
    cout<<"All negative in one side:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;



    return 0;
}