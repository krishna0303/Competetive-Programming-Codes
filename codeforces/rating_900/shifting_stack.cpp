#include<bits/stdc++.h>
using namespace std;
int main(){
 
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        long long *arr=new long long[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        bool flag=false;
        long long count=arr[0];
        arr[0]=0;
        for(int i=1;i<n;i++){
            count+=arr[i];
            if(count>arr[i-1]){
                arr[i]=arr[i-1]+1;
                count=count-(arr[i-1]+1);
            }else{
                flag=true;
                break;
            }
        }
        if(flag){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
        
    }
    return 0;
}