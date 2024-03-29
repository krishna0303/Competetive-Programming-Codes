

#include <bits/stdc++.h>
using namespace std;

/*
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

The first call to next() will return the smallest number in BST. Calling next() again will return the next smallest number in the BST, and so on.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

Try to optimize the additional space complexity apart from the amortized time complexity.
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// TC-O(1)and SC-O(H)--h is height of tree
//  stack<TreeNode *> st;
//  BSTIterator::BSTIterator(TreeNode *root)
//  {
//      TreeNode *temp = root;
//      while (temp != NULL)
//      {
//          st.push(temp);
//          temp = temp->left;
//      }
//  }

// /** @return whether we have a next smallest number */
// bool BSTIterator::hasNext()
// {
//     if (st.empty())
//     {
//         return false;
//     }
//     else
//     {
//         return true;
//     }
// }

// /** @return the next smallest number */
// int BSTIterator::next()
// {
//     TreeNode *temp = st.top();
//     int data = temp->val;
//     st.pop();
//     if (temp->right)
//     {
//         temp = temp->right;
//         while (temp != NULL)
//         {
//             st.push(temp);
//             temp = temp->left;
//         }
//     }
//     return data;
// }

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
