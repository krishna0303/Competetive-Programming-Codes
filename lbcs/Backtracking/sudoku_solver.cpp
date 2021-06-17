


bool isEmpty(int board[][9],int &row,int &col){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]==0){
                row=i;
                col=j;
                return true;
            }
        }
        
    }
    return false;
    
}
bool isCol(int board[][9],int col,int num){
    for(int i=0;i<9;i++){
        if(board[i][col]==num){
            return false;
        }

    }
    return true;
    
}

bool isRow(int board[][9],int row,int num){
    for(int i=0;i<9;i++){
        if(board[row][i]==num){
            return false;
        }

    }
    return true;
    
}

bool isSafe(int board[][9],int row,int col,int num){
    int rowfactor=row-(row%3);
    int colfactor=col-(col%3);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i+rowfactor][j+colfactor]==num){
                return false;
            }

        }
    }
    return true;

}



bool isValid(int board[][9],int row,int col,int num){
    if(isRow(board,row,num)&&isCol(board,col,num)&&isSafe(board,row,col,num)){
        return true;
    }
    return false;
}

bool sudokuSolver(int board[][9]){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Don't print output and return output as specified in the question
  */int row,col;
    if(!isEmpty(board,row,col)){
        return true;
    }
    else{
        for(int i=1;i<=9;i++){
            
            if(isValid(board,row,col,i)){
                board[row][col]=i;
                if(sudokuSolver(board)){
                    return true;
                }
                board[row][col]=0;
                
            }
            
            
            
        }
        
        
    }
    return false;
   
   


}
