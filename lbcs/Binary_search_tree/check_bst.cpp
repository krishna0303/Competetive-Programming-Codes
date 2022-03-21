

/*
Given a binary tree. Check whether it is a BST or not.
Note: We are considering that BSTs can not contain duplicate Nodes.

Example 1:

Input:
    2
 /    \
1      3
Output: 1
Explanation:
The left subtree of root node contains node
with key lesser than the root node’s key and
the right subtree of root node contains node
with key greater than the root node’s key.
Hence, the tree is a BST.

*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

/*

By using inorder traversal
as we know if inorder traverse BST it should be in sorted order otherwise it is not a binary tree
void inorderBST(Node * root,vector<int>&v){
    if(root==NULL){
        return;
    }
    inorderBST(root->left,v);
    v.push_back(root->data);
    inorderBST(root->right,v);

}

class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root)
    {
        // Your code here
        vector<int>v;
        inorderBST(root,v);
        int n=v.size();
        if(n==1){
            return true;
        }
        for(int i=1;i<v.size();i++){
           if(v[i]<=v[i-1]){
               return false;
           }
        }
        return true;



    }
};


This is 2nd approach and best approch without using extra o(n)space
TC-O(n) and SC-O(1)

void solve(TreeNode*root,int &prev,bool &flag){
    if(!root){
        return;
    }
    solve(root->left,prev,flag);
    if(root->val<=prev){
        flag=false;
        return;

    }else{
        prev=root->val;
    }
    solve(root->right,prev,flag);

}
int Solution::isValidBST(TreeNode* A) {
    int prev=INT_MIN;
    bool flag=true;
    solve(A,prev,flag);
    if(flag){
        return 1;
    }else{
        return 0;
    }

}




*/

// } Driver Code Ends

// Here idea is to check if current node falls unnder given interval or not if not then it is not BST
// Here we have assume the range of nodes as intervals
//  like 0<no of edges<100000  >low=0,high=1000001

bool checkBST(Node *root, int low, int high)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data > low && root->data < high)
    {
        bool ans = checkBST(root->left, low, root->data);
        bool ans1 = checkBST(root->right, root->data, high);
        if (!ans || !ans1)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}

class Solution
{
public:
    // Function to check whether a Binary Tree is BST or not.
    bool isBST(Node *root)
    {
        // Your code here
        return checkBST(root, 0, 1000001);
    }
};

// { Driver Code Starts.

// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

void inorder(Node *root, vector<int> &v)
{
    if (root == NULL)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main()
{

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);
        Solution ob;
        if (ob.isBST(root))
            cout << "1\n";

        else
            cout << "0\n";
    }
    return 0;
}

// Position this line where user code will be pasted
//  } Driver Code Ends