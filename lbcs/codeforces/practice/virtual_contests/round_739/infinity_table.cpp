#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
    int t;
    cin>>t;
    while(t--){
        ll k;
        cin>>k;
        ll count=2;
        ll diff=3;
        int j=2;
        while(count<k){
            count+=diff;
            diff+=2;
            j++;
            
            

        }
        int i=1;
        if(count==k){
            cout<<i<<" "<<j<<endl;
            
        }else{
            count-=(diff-2);
            j--;
        
            int temp=j;
            bool flag=false;
            while(i<=temp){
                if(count==k){
                    cout<<i<<" "<<j<<endl;
                    flag=true;
                    break;

                }
                i++;
                count+=1;

            }
            if(!flag){
                i--;
                j--;
                while(j>0){
                    if(count==k){
                        cout<<i<<" "<<j<<endl;
                        break;

                    }
                    j--;
                    count+=1;
                }
            }

        }
        
        
    }
    return 0;
}