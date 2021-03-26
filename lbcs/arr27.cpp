#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;

    vector<int>v;
    v.push_back(1);
    int carry=0;
    for(int i=2;i<=n;i++){
        for(int j=0;j<v.size();j++){
            int temp=v[j]*i+carry;
            carry=0;
            if(temp<10){
                v[j]=temp;
            }else{
                int r=temp%10;
                temp=temp/10;
                v[j]=r;
                if(j==v.size()-1){
                  v.push_back(temp);
                  break;
                }else{
                    carry=temp;
                }
                
            }
            
        }
        // carry=0;

    }
    reverse(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;


    return 0;
}