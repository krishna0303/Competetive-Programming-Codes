#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll binarySearchMin(ll *arr,ll low,ll high,ll l,ll val){
    ll index=-1;
    while(low<=high){
        ll mid=(low+high)/2;
        if((arr[mid]+val)>=l){
            index=mid;
            low=mid+1;
            
            
        }else{
            high=mid-1;
        }

    }
    return index;


}
ll binarySearchMax(ll *arr,ll low,ll high,ll r,ll val){
    ll index=-1;
    while(low<=high){
        ll mid=(low+high)/2;
        if((arr[mid]+val)<=r){
            index=mid;
            high=mid-1;
            
            
        }else{
            low=mid+1;
        }

    }
    return index;
     
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,l,r;
        cin>>n>>l>>r;
        ll*arr=new ll[n];
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n,greater<int>());
        // bool flag=false;
        // for(ll i=1;i<n;i++){
        //     if(arr[i-1]!=arr[i]){
        //         flag=true;
        //         break;
        //     }
        // }
        
            ll count=0;
            for(ll i=0;i<n;i++){
                ll idx1=binarySearchMin(arr,i+1,n-1,l,arr[i]);
                ll idx2=binarySearchMax(arr,i+1,n-1,r,arr[i]);
                if(idx1!=-1&&idx2!=-1){
                      count+=(abs(idx1-idx2)+1);
                }
                
                // cout<<count<<endl;

            }
            cout<<count<<endl;


        
     
        
        
        
        
        
        


    }
    return 0;
}
