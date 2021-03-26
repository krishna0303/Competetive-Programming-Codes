// Given an m x n matrix, find all common elements present in all rows in O(mn) time and one traversal of matrix.
// Example: 

// Input:
// mat[4][5] = {{1, 2, 1, 4, 8},
//              {3, 7, 8, 5, 1},
//              {8, 7, 7, 3, 1},
//              {8, 1, 2, 7, 9},
//             };

// Output: 
// 1 8 or 8 1



#include<bits/stdc++.h>
using namespace std;

void findCommon(int **mat,int n,int m){
    map<int,int>ma;
    for(int i=0;i<m;i++){
        ma[mat[0][i]]+=1;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(ma[mat[i][j]]==i){
                ma[mat[i][j]]=i+1;


                if(i==n-1&&ma[mat[i][j]]==n){
                    cout<<mat[i][j]<<" ";
                }
            }
        }
        
    }
    cout<<endl;



}
int main(){
    int n,m;
    cin>>n>>m;
    int **arr=new int*[n];
    for(int i=0;i<n;i++){
        arr[i]=new int[m];
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    findCommon(arr,n,m);


    return 0;
}
