#include<bits/stdc++.h>
using namespace std;
#define num 8

void displayBoard(int **board){
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            cout<<board[i][j]<<" ";

        }
        cout<<endl;
    }
}

void KnightsTourProblem(int **board,int r,int c,int move){
    if(r<0||c<0||r>=num||c>=num||board[r][c]>0){
        return;
    }
    if(move==(num*num)){
        board[r][c]=move;
        displayBoard(board);
        
        
        return;
    }
    board[r][c]=move;
    KnightsTourProblem(board,r-2,c+1,move+1);
    KnightsTourProblem(board,r-1,c+2,move+1);
    KnightsTourProblem(board,r+1,c+2,move+1);
    KnightsTourProblem(board,r+2,c+1,move+1);
    KnightsTourProblem(board,r+2,c-1,move+1);
    KnightsTourProblem(board,r+1,c-2,move+1);
    KnightsTourProblem(board,r-1,c-2,move+1);
    KnightsTourProblem(board,r-2,c-1,move+1);
    board[r][c]=0;
    return ;
   

}



int main(){

   
    int t;
    cin>>t;
    while(t--){
        int r,c;
        cin>>r>>c;
        int **board=new int*[num];
        for(int i=0;i<num;i++){
            board[i]=new int[num];
            for(int j=0;j<num;j++){
                board[i][j]=0;
            }
        }
        KnightsTourProblem(board,r,c,1);

    }
    return 0;
}