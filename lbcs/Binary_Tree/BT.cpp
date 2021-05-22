#include<bits/stdc++.h>
using namespace std;

struct BinaryTree{
    int info;
    struct BinaryTree *left;
    struct BinaryTree *right;

    BinaryTree(int x){
        info = x;
        left = right = NULL;
    }

};



void preOrderTraversal(struct BinaryTree *root){
    if(root){
        cout<<root->info<<endl;
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void inOrderTraversal(struct BinaryTree *root){
    if(root){
        
        inOrderTraversal(root->left);
        cout<<root->info<<endl;
        inOrderTraversal(root->right);
    }
}
void postOrderTraversal(struct BinaryTree *root){
    if(root){
        
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout<<root->info<<endl;
    }
}


void levelOrderTraversal(struct BinaryTree *root){
struct BinaryTree *temp;
if(!root){
    return;
}
queue<struct BinaryTree *> q;
q.push(root);
while(!q.empty()){
    temp=q.front();
    q.pop();
    cout<<temp->info<<endl;
    if(temp->left){
        q.push(temp->left);
    }
    if(temp->right){
        q.push(temp->right);
    }
}


}
//reverse order traversal  method 1

vector<int> reverseLevelOrder1(BinaryTree *root)
{
    // code here
    BinaryTree * temp;
    vector<int>ans;
    queue<BinaryTree *>q;
    q.push(root);
    while(!q.empty()){
        temp=q.front();
        q.pop();
        ans.push_back(temp->info);
        if(temp->right){
            q.push(temp->right);
        }
        if(temp->left){
            q.push(temp->left);
        }
        
    }
    reverse(ans.begin(),ans.end());
    return ans;
    
}
//reverse level order traversal method 2
vector<int> reverseLevelOrder2(BinaryTree *root)
{
    // code here
    BinaryTree * temp;
    vector<int>ans;
    stack<int>s;
    queue<BinaryTree *>q;
    q.push(root);
    while(!q.empty()){
        temp=q.front();
        q.pop();
        s.push(temp->info);
        if(temp->right){
            q.push(temp->right);
        }
        if(temp->left){
            q.push(temp->left);
        }
        
    }
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    
    return ans;
    
}

//height of a tree
int height(struct BinaryTree* node){
        // code here 
        if(node==NULL){
            return 0;
        }
        int left=height(node->left);
        int right=height(node->right);
        if(left>right){
            return (left+1);
        }else{
            return (right+1);
        }
        
        
    }





int main(){




    return 0;
}