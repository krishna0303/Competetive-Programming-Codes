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
Node *buildTree(string str) {
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
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
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
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
// User Function template for C++

//Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    bool isHeap(struct Node * tree)
    {
        // code here
        queue<Node *>q;
        
        q.push(tree);
        bool flag=false;//use of flag here is to handle complete or almost complete binary tree or not if not then also it is not a heap
        Node*temp;
        while(!q.empty()){
           temp=q.front() ;
           q.pop();
           Node *l=temp->left;
           Node*r=temp->right;
           if(l){
               if(flag||l->data>=temp->data){//here flag will check if flag==true i.e left exist although in previous level right child is not exist it means it is not a complete binary tree
                  return false; 
               }
               q.push(l);
           }else{
               flag=true;
           }
           if(r){
               if(flag||r->data>=temp->data){  //here if flag==true it means without having left child it holds right child which is against of complete binary tree rull i.e it is not a heap
                   return false;
               }q.push(r);
           }else{
               flag=true;
           }
            
        }
        return true;
        
    }
};

// { Driver Code Starts.


int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if(ob.isHeap(root))
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }


    return 0;
}  // } Driver Code Ends