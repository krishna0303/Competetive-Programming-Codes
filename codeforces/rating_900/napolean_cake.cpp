#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int *arr=new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        /*

        idea is to iterate from last ans store this value in some variable and fill 1 till varibale value is grater than zero
        in while loop update count by max(arr[i-1],count-1) there may be some case like 00010503
        
        */
        for(int i=n-1;i>=0;){
            bool flag=true;
            int count=arr[i];
            while(count>0&&i>=0){
                if(i>0){
                      count=max(arr[i-1],count-1);
                }else{
                    count-=1;
                }
                
                arr[i]=1;
                
                i--;
                flag=false;


            }
            if(flag){
                i--;
            }

        }
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }cout<<"\n";

    }
    
    return 0;
}