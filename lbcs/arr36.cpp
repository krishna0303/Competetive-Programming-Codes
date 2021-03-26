#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x;
    cin>>n>>x;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int count=INT_MAX;
    int i=0,j=0;
    int s=0;
    while(i<=j&&j<n){
        while(s<=x&&j<n){
            s+=arr[j];
            j++;
        }
        while(s>x&&i<j){
            count=min(count,j-i);
            s-=arr[i];
            i++;
        }

    }

    cout<<count<<endl;





    return 0;
}