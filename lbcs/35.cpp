// Given an array A[ ] of positive integers of size N, where each value represents the number of chocolates in a packet.
//  Each packet can have a variable number of chocolates. There are M students, 
//  the task is to distribute chocolate packets among M students such that :
// 1. Each student gets exactly one packet.
// 2. The difference between maximum number of chocolates given to a student and minimum 
// number of chocolates given to a student is minimum.


#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int i=0,j=m-1;
    int minDiff=INT_MAX;
    while(j<n){
        int small=arr[j]-arr[i];
        if(small<minDiff){
            minDiff=small;
        }
        i++;
        j++;


    }
    cout<<minDiff<<endl;




    return 0;
}
