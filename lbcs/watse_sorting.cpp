#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int c1,c2,c3;
        cin>>c1>>c2>>c3;
        int arr[5];
        for(int i=0;i<5;i++){
            cin>>arr[i];
        }
        bool flag=false;

        if(c1>=arr[0]){
            c1=c1-arr[0];
        }else{
            flag=true;
        }
        if(c2>=arr[1]){
            c2=c2-arr[1];
        }else{
            flag=true;
        }
        if(c3>=arr[2]){
            c3=c3-arr[2];
        }else{
            flag=true;
        }
        if(c1>0){
            if(c1>=arr[3]){
                c1=c1-arr[3];
                arr[3]=0;
            }else{
                arr[3]=arr[3]-c1;
            }
        }
        if(arr[3]>0){
            if(c3>0){
                if(c3>=arr[3]){
                c3=c3-arr[3];
            }else{
                flag=true;
            }
            }else{
                flag=true;
            }
        }
        if(c2>0){
            if(c2>=arr[4]){
                c2=c2-arr[4];
                arr[4]=0;
            }else{
                arr[4]=arr[4]-c2;
            }
        }
        if(arr[4]>0){
            if(c3>0){
                if(c3>=arr[4]){
                c3=c3-arr[4];
            }else{
                flag=true;
            }
            }else{
                flag=true;
            }
        }
        if(flag){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }



    }
    return 0;
}