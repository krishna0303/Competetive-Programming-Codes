// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.

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
    int target;
    cin>>target;
    // int start=arr[0][0];
    // int end=arr[0][c-1];
    int row=0;
    bool flag=false;
    while((row<r)&&(target>=arr[row][c-1])){
        row++;


    }
    // row--;
    if(row<r-1){
        int i;
        for(i=0;i<c;i++){
            if(arr[row][i]==target){
                cout<<"true"<<endl;
                break;
            }
        }
        if(i==c){
            cout<<"false"<<endl;
        }

    }else{
        cout<<"false"<<endl;

    }
    
    
        
    




    return 0;
}

// leet code accepted solution

// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int row=0;
//         int r =  matrix.size(); // 2 rows  

//   int c = matrix[0].size();
//     // bool flag=false;
//         // cout<<r<<c<<endl;
//     while((row<r)&&(target>matrix[row][c-1])){
//         row++;


//     }
//         if(row<r){
//         int i;
//         for(i=0;i<c;i++){
//             if(matrix[row][i]==target){
                
//                return true;
//             }
//         }
//         }
//         return false;
        
//     }
// };