#include<bits/stdc++.h>
using namespace std;


int minimumNumberOfCoins(int *arr,int n,int v){
    sort(arr,arr+n,greater<int>());
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]<=v){
            count+=1;
            v-=arr[i];
            if(v==0){
                break;
            }
        }

    }
    return count;

}
int main(){

    int n,v;
    cin>>n>>v;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<minimumNumberOfCoins(arr,n,v)<<endl;
    return 0;
}