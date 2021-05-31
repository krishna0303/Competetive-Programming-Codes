
/*

Given a Binary Tree, convert it to Binary Search Tree in such a 
way that keeps the original structure of Binary Tree intact.
 

Example 1:

Input:
      1
    /   \
   2     3
Output: 1 2 3

*/


// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 

void printInorder (struct Node* node)
{
    if (node == NULL)
    return;

    printInorder (node->left);
    printf("%d ", node->data);
    printInorder (node->right);
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
    return NULL;

    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));


            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}

 // } Driver Code Ends
//User function template for C++

/* The Node structure is
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 
*/
//Algorithm
/*

Following is a 3 step solution for converting Binary tree to Binary Search Tree.

1) Create a temp array arr[] that stores inorder traversal of the tree. This step takes O(n) time.
2) Sort the temp array arr[]. Time complexity of this step depends upon the sorting algorithm. 
In the following implementation, Quick Sort is used which takes (n^2) time. This can be done in O(nLogn) 
time using Heap Sort or Merge Sort.

3) Again do inorder traversal of tree and copy array elements to tree nodes one by one. 
This step takes O(n) time.

*/
void inorder(Node *root,vector<int>&v){
    if(root==NULL){
        return;
    }
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
    
}

void setBST(Node *root,vector<int>v,int&i){
    if(root==NULL){
        return;
    }
    setBST(root->left,v,i);
    root->data=v[i];
    (i)++;
    setBST(root->right,v,i);
    
    
}

class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    Node *binaryTreeToBST (Node *root)
    {
        //Your code goes here
        vector<int>v;
        inorder(root,v);
        sort(v.begin(),v.end());
        // for(int i=0;i<v.size();i++){
        //     cout<<v[i]<<" ";
        // }
        // cout<<endl;
        int i=0;
        setBST(root,v,i);
        return root;
        
        
        
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    scanf("%d\n", &t);
    while (t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        Solution obj;
        Node *res = obj.binaryTreeToBST (root);
        printInorder(res);
        cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends