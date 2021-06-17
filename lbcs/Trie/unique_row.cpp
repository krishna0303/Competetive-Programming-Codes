// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	cin>>a[i][j];
    	vector<vector<int>> vec = uniqueRow(a,n,m);
    	for(int i = 0;i<vec.size();i++){
    	    for(int x : vec[i]){
    	        cout<<x<<" ";
    	    }
    	    cout<<"$";
    	}
    	cout<<endl;
    }
}
// } Driver Code Ends


/*You are required to complete this function*/
typedef struct TrieNode{
    
    int wordEnd;
    TrieNode*child[2];
}TrieNode;

TrieNode* createTrie(){
    TrieNode*root=new TrieNode;
    root->wordEnd=0;
   
    for(int i=0;i<2;i++){
        root->child[i]=NULL;
    }
    return root;
}

void insertTrie(TrieNode*root,string s){
    TrieNode*temp=root;
    for(int i=0;i<s.length();i++){
        int idx=int(s[i]);
        if(temp->child[idx]==NULL){
            temp->child[idx]=createTrie();
        }
        temp=temp->child[idx];

    }
    temp->wordEnd+=1;
    
}

bool findTrie(TrieNode *root,string s){
    TrieNode*temp=root;
    for(int i=0;i<s.length();i++){
        int idx=int(s[i]);
        if(temp->child[idx]==NULL){
            return false;
        }
        temp=temp->child[idx];

    }
    if(temp->wordEnd>0){
         
        return true;

    }

}
vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
{
    TrieNode *root=createTrie();
    vector<int>v;
    for(int i=0;i<row;i++){
        string temp="";
        for(int j=0;j<col;j++){
            temp+=to_string(M[i][j]);
            
        }
        if(findTrie(root,temp)==false){
            v.push_back(i);
            insertTrie(root,temp);
        }
    }
    vector<vector<int>>ans;
    for(int  i=0;i<v.size();i++){
        vector<int>v1;
        for(int j=0;j<col;j++){
            v1.push_back(M[v[i]][j]);
            
        }
        ans.push_back(v1);
    }
    return ans;

 

}