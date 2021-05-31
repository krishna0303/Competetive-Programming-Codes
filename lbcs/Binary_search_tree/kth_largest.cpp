// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

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
    Node* root = new Node(stoi(ip[0]));
        
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
                
            // Create the left child for the current node
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
/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
/*

Kth Smallest Element in BST
 idea is to traverse inorder till k if k is greater than nodes present in tree return -1
void inorder(Node* root, int&data,int& k){
    if(root==NULL){
        return;
    }
    inorder(root->left,data,k);
    if(k>0){
        data=root->data;
        k--;
    }else{
        return;
    }
    inorder(root->right,data,k);
}

class Solution{
  public:
    // Return the Kth smallest element in the given BST 
    int KthSmallestElement(Node *root, int k)
    {
        //add code here.
        int data=0;
        inorder(root,data,k);
        if(k!=0){
            return -1;
        }
        return data;
        
    }
};

*/

//Kth Largest element in BST
//idea is to go opposite inorder because we have to find kth largest element 
//so we have to go to first deep rightmost and then come back until k

void inorder(Node *root,int&data,int &k){
    if(root==NULL){
        return;
    }
    inorder(root->right,data,k);
    if(k>0){
       data=root->data;
       k--;
       
    }else{
        return;
    }
    inorder(root->left,data,k);
    
}



// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
    public:
    int kthLargest(Node *root, int k)
    {
        //Your code here
        int data=0;
        inorder(root,data,k);
        return data;
        
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int k;
        cin>>k;
        getchar();
        
        Solution ob;
        cout << ob.kthLargest( head, k ) << endl;
    }
    return 1;
}  // } Driver Code Ends