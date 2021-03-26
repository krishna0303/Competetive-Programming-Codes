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
    int minimal=arr[0];
    int profit=0;
    for(int i=1;i<n;i++){
        if(arr[i]<minimal){
            minimal=arr[i];

        }else{
            int smallProfit=(arr[i]-minimal);
            if(smallProfit>profit){
                profit=smallProfit;
            }
        }
    }
    cout<<profit<<endl;
    
    
    return 0;
}