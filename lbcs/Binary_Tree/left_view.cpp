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
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int>v;
   if(!root){
       return v;
       
   }
   
   Node *temp;
   queue<Node*>q;
   q.push(root);
   while(!q.empty()){
        int n = q.size();
         
        // Traverse all nodes of current level
        for(int i = 1; i <= n; i++)
        {
            Node* temp = q.front();
            q.pop();
                 
            // Print the left most element
            // at the level
            if (i == 1)
                v.push_back(temp->data);
             
            // Add left node to queue
            if (temp->left != NULL)
                q.push(temp->left);
 
            // Add right node to queue
            if (temp->right != NULL)
                q.push(temp->right);
        }
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
    vector<int>ans=leftView(root);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
    return 0;
}