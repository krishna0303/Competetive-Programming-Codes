/*

Diagonal Traversal of Binary Tree
Difficulty Level : Medium
Last Updated : 08 Feb, 2021
Consider lines of slope -1 passing between nodes. Given a Binary Tree, print all diagonal elements in a binary tree belonging to the same line.

Input : Root of below tree
for image of tree visit this page
https://www.geeksforgeeks.org/diagonal-traversal-of-binary-tree/   

Output : 
Diagonal Traversal of binary tree : 
 8 10 14
 3 6 7 13
 1 4

*/

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


//Function to return a list containing elements of left view of the binary tree.
//basic idea is  to give no if left then increament of cureewnt value and if right then move right with same number
vector<int> diagonalTraversal(Node *root)
{
   // Your code here
   vector<int>v;
   if(!root){
       return v;
       
   }
   
   Node *temp;
   queue<pair<Node*,int>>q;
   q.push({root,0});
   map<int,vector<int>>m;
   
   while(!q.empty()){
        temp=q.front().first;
        int h=q.front().second;
        q.pop();
        m[h].push_back(temp->data);
        if(temp->left){
            q.push({temp->left,h+1});
        }
        if(temp->right){
            q.push({temp->right,h});

        }
   }
   for(auto it:m){
       v.insert(v.end(),it.second.begin(),it.second.end());
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
    vector<int>ans=diagonalTraversal(root);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
    return 0;
}
