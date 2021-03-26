
//Given a matrix of size R*C. Traverse the matrix in spiral form.
//Input:
// R = 4, C = 4
// matrix[][] = {{1, 2, 3, 4},
//            {5, 6, 7, 8},
//            {9, 10, 11, 12},
//            {13, 14, 15,16}}
// Output: 
// 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10


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
    int top=0,down=r-1,left=0,right=c-1;
    int dir=0;
    while(top<=down&&left<=right){
        if(dir==0){
            for(int i=left;i<=right;i++){
                cout<<arr[top][i]<<" ";

            }
            top+=1;

        }else if(dir==1){
            for(int i=top;i<=down;i++){
                cout<<arr[i][right]<<" ";

            }
            right-=1;
        }else if(dir==2){
            for(int i=right;i>=left;i--){
                cout<<arr[down][i]<<" ";
            }
            down-=1;

        }else if(dir==3){
            for(int i=down;i>=top;i--){
                cout<<arr[i][left]<<" ";
            }
            left+=1;
        }
        dir=(dir+1)%4;
    }
    cout<<endl;



    return 0;
}