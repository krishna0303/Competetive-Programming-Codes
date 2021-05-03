#include<bits/stdc++.h>
using namespace std;

struct BinaryTree{
    int info;
    struct BinaryTree *left;
    struct BinaryTree *right;

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
    if(root){
        
        
    }
}





int main(){
    return 0;
}