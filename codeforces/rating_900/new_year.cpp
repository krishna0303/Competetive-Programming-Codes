#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int val=(n/2020);
        int x=(n%2020);
        val=abs(val-x);
        int new_val=(2020*val)+(2021*x);
        if(new_val==n){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
        
    }
    return 0;
}