#include<bits/stdc++.h>
using namespace std;


void arrange(int*arr, int n){
    int i=0;
    while(i<n){
        if((i+1)%2!=0&&(arr[i]>0)){
            // int temp=arr[i];
            int j;
            int index=-1;
            bool flag=false;
            for( j=i+1;j<n;j++){
                if(arr[j]<0){
                    index=j;
                    flag=true;
                    break;
                    

                }
            }
            if(flag){
                int temp=arr[index];
            for(int k=index;k>i;k--){
                arr[k]=arr[k-1];
            }
            arr[i]=temp;
            i+=2;

            }else{
                break;
            }
            
            

        }else if((i+1)%2==0 && (arr[i]<0)){
            int j;
            int index=-1;
            bool flag=false;
            for( j=i+1;j<n;j++){
                if(arr[j]>0){
                    index=j;
                    flag=true;
                    break;
                    

                }
            }
             if(flag){
                int temp=arr[index];
            for(int k=index;k>i;k--){
                arr[k]=arr[k-1];
            }
            arr[i]=temp;
            i+=2;

            }else{
                break;
            }
        }
        else{
            i++;

        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    arrange(arr,n);



    return 0;
}