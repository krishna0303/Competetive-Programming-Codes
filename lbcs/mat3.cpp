#include<bits/stdc++.h>
using namespace std;
int main(){
    int r,c;
    cin>>r>>c;
    int **arr=new int*[r];
    for(int i=0;i<r;i++){
        arr[i]=new int[c];
        for(int j=0;j<c;j++){
            cin>>arr[i][j];
        }
    }

    int max=INT_MIN,min=INT_MAX;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(arr[i][j]>max){
                max=arr[i][j];
            }
            if(arr[i][j]<min){
                min=arr[i][j];
            }
        }
    }
    int desire=((r*c)+1)/2;
    
    while(min<max){
        int mid=(min+max)/2;
        int possible=0;
        for(int i=0;i<r;i++){
            possible+=upper_bound(arr[i],arr[i]+c,mid)-arr[i];
        }
        if(possible<desire){
            min=mid+1;
        }else{
            max=mid;
        }
        
    }
    cout<<min<<endl;




    return 0;
} 

//geegks for geeks accepted
//  int max=INT_MIN,min=INT_MAX;
//     for(int i=0;i<r;i++){
//         for(int j=0;j<c;j++){
//             if(arr[i][j]>max){
//                 max=arr[i][j];
//             }
//             if(arr[i][j]<min){
//                 min=arr[i][j];
//             }
//         }
//     }
//     int desire=((r*c)+1)/2;
    
//     while(min<max){
//         int mid=(min+max)/2;
//         int possible=0;
//         for(int i=0;i<r;i++){
//             possible+=upper_bound(arr[i],arr[i]+c,mid)-arr[i];
//         }
//         if(possible<desire){
//             min=mid+1;
//         }else{
//             max=mid;
//         }
        
//     }