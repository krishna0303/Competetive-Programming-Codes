
#include <bits/stdc++.h>
using namespace std;

/*
Problem Description

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).



Problem Constraints
1 <= number of nodes <= 105



Input Format
First and only argument is the root node of the binary tree.



Output Format
Return 0 / 1 ( 0 for false, 1 for true ).



Example Input
Input 1:

    1
   / \
  2   2
 / \ / \
3  4 4  3
Input 2:

    1
   / \
  2   2
   \   \
   3    3


Example Output
Output 1:

 1
Output 2:

 0
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
bool solve(TreeNode *root1, TreeNode *root2)
{
    if (!root1 && !root2)
    {
        return true;
    }
    if (!root1 && root2 || (root1 && !root2))
    {
        return false;
    }
    if (root1->val != root2->val)
    {
        return false;
    }
    bool ans1 = solve(root1->left, root2->right);
    bool ans2 = solve(root1->right, root2->left);
    if (ans1 && ans2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int isSymmetric(TreeNode *A)
{
    return solve(A->left, A->right);
}
