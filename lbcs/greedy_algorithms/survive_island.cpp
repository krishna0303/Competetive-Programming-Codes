#include<bits/stdc++.h>
using namespace std;

int main(){
    int s,n,m;
    cin>>s>>n>>m;
    if(n<m){
        cout<<"NO\n";
        
    }else{

    
    int count=1;
    int val=n/m;
    int rem=n%m;
    while(val<s){
        count+=1;
        int v=(n+rem)/m;
        rem=(n+rem)%m;
        val+=v;
    }
    cout<<"YES "<<count<<endl;
    }
    return 0;
}