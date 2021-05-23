#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
    int data;
    Node *left,*right;
}Node;

Node* createTree(int n){
    Node *root=new Node();
    root->data=n;
    root->left=root->right=NULL;
    return root;
}



//important algo same 
//same as topview only we have to upadte all the values and final one is our answer
//Function to return a list containing elements of left view of the binary tree.
// basic idea is to maintain the height of each node and consider
vector<int> topView(Node *root)
    {
        //Your code here
    vector<int>v;
   if(!root){
       return v;
       
   }
   
   Node *temp;
   queue<pair<Node*,int>>q;
   map<int,int>m;
   q.push(make_pair(root,0));
   
   while(!q.empty()){
       temp=q.front().first;
       int h=q.front().second;
       q.pop();
       if(!m[h]){
           m[h]=temp->data;
       }
       if(temp->left){
           q.push(make_pair(temp->left,h-1));
       }
       if(temp->right){
           q.push(make_pair(temp->right,h+1));
       }
       
       
       
       
       
       
       
   }
   for(auto it:m){
       v.push_back(it.second);
   }
   return v;
   
    }



int main(){
    Node*root=createTree(1);
    root->left=createTree(2);
    root->right=createTree(3);
    root->left->left=createTree(4);
    root->left->right=createTree(5);
    root->right->left=createTree(6);
    root->right->right=createTree(7);
    root->left->left->right=createTree(8);
    vector<int>ans=topView(root);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
    return 0;
}