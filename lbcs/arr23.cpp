

// Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K.
//Efficinet approach

#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];

    }
    map<int,int>m;
    for(int i=0;i<n;i++){
        m[arr[i]]+=1;

    }
    int count=0;
    for(int i=0;i<n;i++){
        count+=m[k-arr[i]];
        if(k-arr[i]==arr[i]){
            count--;
        }

    }
    cout<<count/2<<endl;
    return 0;
}