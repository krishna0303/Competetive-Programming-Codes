// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    bool isSafe(int **board,int num,int r,int c){
    if(r<0||c<0||r>=num||c>=num||board[r][c]!=0){
        return false;
    }
    return true;
    
   

}

//here basic idea is to apply bfs for minimum path
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
	{
	    int **board=new int*[n];
	    for(int i=0;i<n;i++){
	        board[i]=new int[n];
	        for(int j=0;j<n;j++){
	            board[i][j]=0;
	        }
	    }
	    queue<pair<int,int>>q;
	    int x1=KnightPos[0];
	    int y1=KnightPos[1];
	    int x2=TargetPos[0];
	    int y2=TargetPos[1];
	    q.push(make_pair(x1-1,y1-1));
	    while(!q.empty()){
	        auto it=q.front();
	        int i=it.first;
	        int j=it.second;
	        q.pop();
	        if(isSafe(board,n,i+1,j+2)){
	            board[i+1][j+2]=board[i][j]+1;
	            q.push(make_pair(i+1,j+2));
	            
	        }
	        if(isSafe(board,n,i-1,j+2)){
	            board[i-1][j+2]=board[i][j]+1;
	            q.push(make_pair(i-1,j+2));
	            
	        }
	        if(isSafe(board,n,i-2,j+1)){
	            board[i-2][j+1]=board[i][j]+1;
	            q.push(make_pair(i-2,j+1));
	            
	        }
	        if(isSafe(board,n,i+2,j+1)){
	            board[i+2][j+1]=board[i][j]+1;
	            q.push(make_pair(i+2,j+1));
	            
	        }
	        if(isSafe(board,n,i-1,j-2)){
	            board[i-1][j-2]=board[i][j]+1;
	            q.push(make_pair(i-1,j-2));
	            
	        }
	        if(isSafe(board,n,i+1,j-2)){
	            board[i+1][j-2]=board[i][j]+1;
	            q.push(make_pair(i+1,j-2));
	            
	        }
	        if(isSafe(board,n,i-2,j-1)){
	            board[i-2][j-1]=board[i][j]+1;
	            q.push(make_pair(i-2,j-1));
	            
	        }
	        if(isSafe(board,n,i+2,j-1)){
	            board[i+2][j-1]=board[i][j]+1;
	            q.push(make_pair(i+2,j-1));
	            
	        }
	        
	    }
	    return board[x2-1][y2-1];
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends