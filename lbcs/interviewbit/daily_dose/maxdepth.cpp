/*
Asked In:
GOLDMAN SACHS
FACEBOOK
BLOOMBERG
MICROSOFT

Given a binary tree, find its maximum depth.

The maximum depth of a binary tree is the number of nodes along the longest path from the root node down to the farthest leaf node.

NOTE : The path has to end on a leaf node.

Example :

         1
        /
       2
max depth = 2.



*/

/*
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepthUtil(TreeNode *root, int current)
{
    if (!root)
    {
        return current - 1;
    }

    int leftD, rightD;

    leftD = maxDepthUtil(root->left, current + 1);

    rightD = maxDepthUtil(root->right, current + 1);

    return max(leftD, rightD);
}

int maxDepth(TreeNode *A)
{
    if (!A)
    {
        return 0;
    }
    return maxDepthUtil(A, 1);
}
