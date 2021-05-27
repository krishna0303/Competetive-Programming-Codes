/*
Some Interesting Facts:  

Inorder traversal of BST always produces sorted output.
We can construct a BST with only Preorder or Postorder or Level Order traversal. Note that we can always get
inorder traversal by sorting the only given traversal.

*/

#include<bits/stdc++.h>
using namespace std;
typedef struct BST{
    int data;
    struct BST *left;
    struct BST *right;
}bst;

bst* find (bst* root,int data){
    if(!root){
        return NULL;
    }
    if(root->data>data){
        find(root->left,data);
    }else if(root->data<data){
        find(root->right,data);
    }
    return root;
}

bst* FindMax(bst* root){
    bst* temp=root;
    bst*n=root;
    while(n!=NULL){
        if(n->data>temp->data){
            temp=n;
        }
        n=n->right;
    }
    return temp;

}

void insert(bst * root, int data){
    bst*n=new bst();
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    if(!root){
        root=n;
    }else{
        bst *temp=root;
    while(temp!=NULL){
        if(temp->data>data){
                if(temp->left==NULL){
                    temp->left=n;
                }
                temp=temp->left;
        }else if(temp->data<data){
            if(temp->right==NULL){
                temp->right=n;
            }
            temp=temp->right;
        }
    }

    }
    
}
bst* deleteBST(bst* root,int data){
    bst* temp;
      if(!root){
         return NULL;
          
      }
      else if(data<root->data){
          root->left=deleteBST(root->left,data);

      }else if(data>root->data){
          root->right=deleteBST(root->right,data);
      }else{
          if(root->right&&root->left){
              temp=FindMax(root->left);
              root->data=temp->data;
              root->left=deleteBST(root->left,root->data);
              
          }else{
              temp=root;
              if(root->left==NULL){
                  root=root->right;
              }else if(root->right==NULL){
                  root=root->left;
              }
              free(temp);
          }
      }
      return root;
}


int main(){
    
    return 0;
}