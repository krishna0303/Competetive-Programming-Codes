// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++]

/*

first of all check all the constraints and it i and j react to the last cell then print it or push it in vector
after that explore all the four direction of maze and after explore of all direction mark that cell unvisited and backtrack
also remove the current character of string during backtracking


*/


void RatInMaze(vector<vector<int>> &m, int n,bool**visited,vector<string>&ans,string s,int i,int j){
    if(i<0||i>=n||j<0||j>=n||(m[i][j]==0)||visited[i][j]){
        return;
    }
    if(i==n-1&&j==n-1){
        ans.push_back(s);
        return;
    }
    visited[i][j]=true;
    RatInMaze(m,n,visited,ans,s+'L',i,j-1);
    RatInMaze(m,n,visited,ans,s+'R',i,j+1);
    RatInMaze(m,n,visited,ans,s+'U',i-1,j);
    RatInMaze(m,n,visited,ans,s+'D',i+1,j);
    visited[i][j]=false;
    s=s.substr(0,s.length()-1);
    return;
}

class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        bool**visited=new bool*[n];
        for(int i=0;i<n;i++){
            visited[i]=new bool[n]();
        }
        vector<string>ans;
        string s="";
        RatInMaze(m,n,visited,ans,s,0,0);
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends