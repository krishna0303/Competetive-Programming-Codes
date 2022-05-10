
#include <bits/stdc++.h>
using namespace std;

/*
Given a binary tree denoted by root node A and a leaf node B from this tree.

 It is known that all nodes connected to a given node (left child, right child and parent) get burned in 1 second. Then all the nodes which are connected through one intermediate get burned in 2 seconds, and so on.

You need to find the minimum time required to burn the complete binary tree.
*/

/*

my solution

int height(TreeNode*root){
    if(!root){
        return 0;
    }
    int l=height(root->left);
    int r=height(root->right);
    return 1+max(l,r);
}

TreeNode*find(TreeNode*root,int data,bool &flag,int count,int &ans){
    if(!root){
        return NULL;
    }
    if((root->left&&root->left->val==data)||(root->right&&root->right->val==data)){
        count+=1;
        ans=count;
        return root;
    }

    TreeNode*l=find(root->left,data,flag,count+1,ans);
    TreeNode*r=find(root->right,data,flag,count+1,ans);
    if(l){
        flag=true;
        return l;
    }else{
        return r;
    }
}
int Solution::solve(TreeNode* A, int B) {
    bool flag=false;
    int count=0;
    TreeNode*pos=find(A,B,flag,0,count);
    // cout<<count<<endl;

    int l=INT_MIN,r=INT_MIN,p=INT_MIN;
    if(pos->left->val==B){
        if(count==0){
            flag=true;
        }
        l=height(pos->right);
    }else if(pos->right->val==B){
        l=height(pos->left);
    }
    if(flag){
       r=height(A->right);
    }else{
        r=height(A->left);
    }
    int ans=0;
    // cout<<count<<" "<<l<<" "<<r<<endl;
    if(count<l){
       ans=(r-(l-count))+l+1;
    }else{
        ans=count+r;
    }
    return ans;




}


*/

// for better understanding of this watch striver video
// this solution can work for any node burn tree problem either target node is leaf node or any node

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int solve(TreeNode *A, int B)
{

    map<TreeNode *, TreeNode *> mp;
    TreeNode *start;
    queue<TreeNode *> q;
    vector<int> visited(100000, -1);
    q.push(A);
    // To inserting all nodes parent
    while (q.empty() == false)
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = q.front();
            if (temp->val == B)
                start = temp;
            q.pop();
            if (temp->left != NULL)
            {
                q.push(temp->left);
                mp[temp->left] = temp;
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
                mp[temp->right] = temp;
            }
        }
    }

    queue<TreeNode *> nq;
    nq.push(start);
    int burnTime = 0;
    while (nq.empty() == false)
    {
        int size = nq.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *Temp = nq.front();
            nq.pop();
            visited[Temp->val] = 1;
            if (mp.find(Temp) != mp.end())
            {
                TreeNode *parent = mp[Temp];
                if (visited[parent->val] == -1)
                {
                    visited[parent->val] = 1;
                    nq.push(parent);
                }
            }
            if (Temp->left != NULL && visited[Temp->left->val] == -1)
            {
                visited[Temp->left->val] = 1;
                nq.push(Temp->left);
            }
            if (Temp->right != NULL && visited[Temp->right->val] == -1)
            {
                visited[Temp->right->val] = 1;
                nq.push(Temp->right);
            }
        }
        burnTime++;
    }

    return burnTime - 1;
}