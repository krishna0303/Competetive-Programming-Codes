
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;



int main()
{
    int t;
    cin>>t;
    while(t--){
       ll n,m;
       cin>>n>>m;
       ll count=0;
       ll *arr=new ll[n+1];
       for(int i=0;i<=n;i++){
           arr[i]=1;
       }
       
       
       for(int i=2;i<=n;i++){
           int small=m%i;
           count+=arr[small];
           for(int j=small;j<=n;j+=i){
               arr[j]+=1;
           }
       }
       
       cout<<count<<endl;
    }
	
	return 0;
}