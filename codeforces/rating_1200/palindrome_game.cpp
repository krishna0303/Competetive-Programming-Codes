#include<bits/stdc++.h>
using namespace std;

void solve(int n,string s){
    int zero_count=0;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            zero_count+=1;
        }
    }
    if(zero_count==1){
        cout<<"BOB\n";
        return;
    }
    if(zero_count%2==0){
        cout<<"BOB\n";
        return;
    }
    cout<<"ALICE\n";
    return;


}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        solve(n,s);
        

    }
    return 0;
}