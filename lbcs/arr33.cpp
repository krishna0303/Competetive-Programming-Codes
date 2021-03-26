
// Given an array arr of size n and an integer X. 
// Find if there's a triplet in the array which sums up to the given integer X.

#include<bits/stdc++.h>
using namespace std;

//first brute force approach O(N^3)
bool find3Numbers1(int arr[], int n, int X)
    {
        //Your Code Here
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(arr[i]+arr[j]+arr[k]==X){
                        return true;
                    }
                    
                    
                }
            }
        }
        return false;
    }

    //second approach TC-O(N^2) && SC-O(N)

bool find3Numbers2(int arr[], int n, int x)
    {
       
        for(int i=0;i<n;i++){
             unordered_set<int>s;
            int curr=x-arr[i];
            for(int j=i+1;j<n;j++){
                if(s.find(curr-arr[j])!=s.end()){
                    return true;
                }else{
                    s.insert(arr[j]);

                }
            }

        }
        return false;
    } 
//Third and efficient approach TC-(N^2) and SC-O(1)   

bool find3Numbers3(int arr[], int n, int x)
    {
        //Your Code Here
        sort(arr,arr+n);
        for(int i=0;i<n;i++){
        int l=i+1;
        int r=n-1;
        while(l<r){
            if(arr[i]+arr[l]+arr[r]==x){
                return true;
            }
            else if(arr[i]+arr[l]+arr[r]<x){
                l++;
            }else{
                r--;
            }
        }
        }
        return false;
    }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x;
    cin>>n>>x;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    cout<<find3Numbers3(arr,n,x)<<endl;

    

    




    return 0;
}
