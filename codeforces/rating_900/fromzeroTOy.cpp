#include<bits/stdc++.h>
using namespace std;
int main(){

    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        int count=0;
        int c=0;
        int temp=y;
        while(temp!=0){
            count++;
            temp/=10;
        }
        temp=y;
        count=count-1;
        
        while(count>=0){
            
            int val=x*pow(10,count);
            // cout<<val<<endl;
            c+=temp/val;
            temp=(temp%val);
            count-=1;



        }
        if(temp>0){
            c+=temp;
        }
        cout<<c<<endl;
    }
    return 0;
}