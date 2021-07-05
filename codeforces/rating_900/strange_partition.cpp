#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,x;
        cin>>n>>x;
        ll *arr=new ll[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        ll count1=0;
        ll count2=0;
        for(int i=0;i<n;i++){
            count2+=arr[i];
            count1+=(arr[i]/x);
            ll a=(arr[i]%x);
            if(a!=0){
                count1+=1;
            }
            
        }
        
        ll y=count1;
        ll x1=(count2/x);
        if(count2%x!=0){
            x1+=1;
        }
        cout<<x1<<" "<<y<<endl;
        
        
    }
    return 0;
}