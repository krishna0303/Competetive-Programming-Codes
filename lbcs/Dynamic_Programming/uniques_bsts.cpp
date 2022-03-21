#include <bits/stdc++.h>
using namespace std;

/*

Given A, generate all structurally unique BST’s (binary search trees) that store values 1…A.

Input Format:

The first and the only argument of input contains the integer, A.
Output Format:

Return a list of tree nodes representing the generated BST's.
Constraints:

1 <= A <= 15
Example:

Input 1:
    A = 3

Output 1:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

*/

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

vector<TreeNode *> generate(int lo, int hi)
{
    vector<TreeNode *> cans;
    if (lo > hi)
    {
        cans.push_back(NULL);
        return cans;
    }
    for (int i = lo; i <= hi; i++)
    {
        vector<TreeNode *> l = generate(lo, i - 1);
        vector<TreeNode *> r = generate(i + 1, hi);
        for (int x = 0; x < l.size(); x++)
        {
            for (int y = 0; y < r.size(); y++)
            {
                TreeNode *node = new TreeNode(i);
                node->left = l[x];
                node->right = r[y];
                cans.push_back(node);
            }
        }
        l.clear();
        r.clear();
    }
    return cans;
}
vector<TreeNode *>generateTrees(int A)
{
    return generate(1, A);
}
