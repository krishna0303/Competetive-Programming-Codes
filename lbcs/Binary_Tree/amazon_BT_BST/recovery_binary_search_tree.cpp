#include <bits/stdc++.h>
using namespace std;

/*
Two elements of a binary search tree (BST) are swapped by mistake.

Tell us the 2 values swapping which the tree will be restored.

Note:

A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

Example :


Input :
         1
        / \
       2   3

Output :
       [1, 2]

Explanation : Swapping 1 and 2 will change the BST to be
         2
        / \
       1   3
which is a valid BST
*/

/*

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void solve(TreeNode *root, int &prev, vector<int> &node)
{
    if (!root)
    {
        return;
    }
    solve(root->left, prev, node);
    if (root->val > prev)
    {
        prev = root->val;
    }
    else
    {
        node.push_back(prev);
        node.push_back(root->val);
    }
    solve(root->right, prev, node);
}
vector<int> recoverTree(TreeNode *A)
{
    vector<int> ans;
    int prev = INT_MIN;
    solve(A, prev, ans);
    if (ans.size() > 2)
    {
        vector<int> temp;

        temp.push_back(ans[ans.size() - 1]);
        temp.push_back(ans[0]);
        return temp;
    }
    else
    {
        swap(ans[0], ans[1]);
        return ans;
    }
}
