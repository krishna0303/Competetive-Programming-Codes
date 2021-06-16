#include<bits/stdc++.h>
using namespace std;

void printSolutionMat(int**mat,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<mat[i][j]<<" ";
        }cout<<endl;
    }
    cout<<endl;

}

bool isValid(int**board,int n,int row, int col){
    for(int i=row-1;i>=0;i--){
        if(board[i][col]==1){
            return false;
        }
    }
    for(int i=row-1,j=col-1;(i>=0 &&j>=0);i--,j--){
        if(board[i][j]==1){
            return false;
        }
        
    }
    for(int i=row-1,j=col+1;i>=0 &&j<n;i--,j++){
        if(board[i][j]==1){
            return false;
        }
        
    }
    return true;
    
    

}

void NQueen(int**mat,int n,int i){
    if(i==n){
        printSolutionMat(mat,n);
        return;
    }
    for(int j=0;j<n;j++){
        if(isValid(mat,n,i,j)){
            mat[i][j]=1;
            NQueen(mat,n,i+1);
            mat[i][j]=0;
            
        }
    }
    
}



int main(){
    int n;
    cin>>n;
    int**mat=new int*[n];
    for(int i=0;i<n;i++){
        mat[i]=new int[n];
        for(int j=0;j<n;j++){
            mat[i][j]=0;
        }
    }
    
    NQueen(mat,n,0);
    

    return 0;
}