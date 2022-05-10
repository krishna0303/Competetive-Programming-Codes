// result for dfs

#include <bits/stdc++.h>
using namespace std;

// watch striver video algods and striver video for better understanding
/*


Maximum sub-tree sum in a Binary Tree such that the sub-tree is also a BST:
Given a binary tree, the task is to print the maximum sum of nodes of a sub-tree which is also a Binary Search Tree.
Examples:

Input :
       7
      /  \
     12    2
    /  \    \
   11  13    5
  /         / \
 2         1   38

Output:44
BST rooted under node 5 has the maximum sum
       5
      / \
     1   38

Input:
      5
     /  \
    9    2
   /      \
  6        3
 / \
8   7

Output: 8
Here each leaf node represents a binary search tree
also a BST with sum 5 exists
     2
      \
       3
But the leaf node 8 has the maximum sum.

*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

typedef struct result
{
    int Min;
    int Max;
    int sum;
    // is this subtree a valid bst?
    bool valid;
} result;

class Solution
{
    // a member that keeps the max sum for dfs to update
    int m_max_sum = 0;

public:
    result dfs(TreeNode *root)
    {
        if (!root)
        {
            // return INT_MAX as min and INT_MIN as max on root==NULL, because we want leaf nodes to always be computed as valid BSTs,
            return {INT_MAX, INT_MIN, 0, true};
        }
        // recursively compute on left and right children
        result l_result = dfs(root->left);
        result r_result = dfs(root->right);

        // Compute return values based on left and right results
        int ret_min = min(min(l_result.Min, r_result.Min), root->val);
        int ret_max = max(max(l_result.Max, r_result.Max), root->val);
        int ret_sum = root->val + l_result.sum + r_result.sum;
        bool ret_valid = l_result.valid && r_result.valid && (l_result.Max < root->val) && (r_result.Min > root->val);

        // Update the max sum if the current subtree is a valid bst
        if (ret_valid)
            m_max_sum = max(m_max_sum, ret_sum);

        return {ret_min, ret_max, ret_sum, ret_valid};
    }

    int maxSumBST(TreeNode *root)
    {
        result ret = dfs(root);
        return m_max_sum;
    }
};