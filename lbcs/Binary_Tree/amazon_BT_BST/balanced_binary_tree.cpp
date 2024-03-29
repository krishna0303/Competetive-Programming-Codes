#include <bits/stdc++.h>
using namespace std;

/*
Given a binary tree, determine if it is height-balanced.

Height-balanced binary tree  : is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Example :

Input :
          1
         / \
        2   3

Return : True or 1

Input 2 :
         3
        /
       2
      /
     1

Return : False or 0
         Because for the root node, left subtree has depth 2 and right subtree has depth 0.
         Difference = 2 > 1.
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int solve(TreeNode *root, bool &ans)
{
    if (!root)
    {
        return 0;
    }
    int l = solve(root->left, ans);
    int r = solve(root->right, ans);
    if (abs(l - r) > 1)
    {
        ans = false;
    }
    return 1 + max(l, r);
}
int isBalanced(TreeNode *A)
{
    bool ans = true;
    solve(A, ans);
    if (ans)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
