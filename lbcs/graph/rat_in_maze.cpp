// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void RatInMaze(vector<vector<int>> &m,int i,int j,int n,bool **visited,vector<string>&ans,string str){
        if(i<0||j<0||i>=n||j>=n||m[i][j]==0||visited[i][j]==true){
            return;
        }
        if(i==n-1&&j==n-1){
            ans.push_back(str);
           
            return;
        }
        visited[i][j]=true;
        RatInMaze(m,i-1,j,n,visited,ans,str+"U");
        RatInMaze(m,i+1,j,n,visited,ans,str+"D");
        RatInMaze(m,i,j-1,n,visited,ans,str+"L");
        RatInMaze(m,i,j+1,n,visited,ans,str+"R");
        
        visited[i][j]=false;
        return;
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>ans;
        bool **visited=new bool *[n];
        for(int i=0;i<n;i++){
            visited[i]=new bool[n];
            for(int j=0;j<n;j++){
                // if(m[i][j]==0){
                //     visited[i][j]=true;
                // }
                // else{
                //     visited[i][j]=false;
                // }
                visited[i][j]=false;
            }
        }
        RatInMaze(m,0,0,n,visited,ans,"");
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