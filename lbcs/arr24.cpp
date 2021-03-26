

// Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K.
//Efficinet approach

#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    int *arr1=new int[n1];
    for(int i=0;i<n1;i++){
        cin>>arr1[i];

    }
    int *arr2=new int[n2];
    for(int i=0;i<n2;i++){
        cin>>arr2[i];

    }
    int *arr3=new int[n3];
    for(int i=0;i<n3;i++){
        cin>>arr3[i];

    }
    
    int  i=0,j=0,k=0;
     int prev1, prev2, prev3;
 
    // Initialize prev1, prev2, 
    // prev3 with INT_MIN
    vector<int>v;
    prev1 = prev2 = prev3 = INT_MIN;
    while(i<n1&&j<n2&&k<n3){
        
        while(arr1[i]==prev1&&i<n1){
            i++;
        
        }
        while(arr2[j]==prev2&&j<n2){
            j++;
        
        }
        while(arr3[k]==prev3&&k<n3){
            k++;
        
        }

        if(arr1[i]==arr2[j]&&arr2[j]==arr3[k]){
            v.push_back(arr1[i]);
            prev1 = arr1[i];
            prev2 = arr2[j];
            prev3 = arr3[k];
            i++;
            j++;
            k++;
        }else if(arr1[i]<arr2[j]){
            prev1=arr1[i];
            i++;
            
        }else if(arr2[j]<arr3[k]){
            prev2=arr2[j];
            j++;
            
        }else{
            prev3=arr3[k];
            k++;
            
        }
        

    }
    // cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}