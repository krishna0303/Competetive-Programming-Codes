#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int count=9;
        while(n--){
            
            cout<<count;
            count-=1;
            if(count==-1){
                count=9;
            }

        }
        cout<<endl;
        
        
    }
    return 0;
}