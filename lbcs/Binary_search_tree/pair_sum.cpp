// { Driver Code Starts
// C++ implementation to count pairs from two
#include <bits/stdc++.h>
using namespace std;

// structure of a node of BST
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}

int countPairs(Node* root1, Node* root2, int x);

// Driver code
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node* root1 = NULL;
        Node* root2 = NULL;
        int n1, n2, k;
        cin>>n1;
        for(int i=0; i<n1; i++)
        {
            cin>>k;
            insert(&root1, k);
        }
        cin>>n2;
        for(int i=0; i<n2; i++)
        {
            cin>>k;
            insert(&root2, k);
        }
        int s;
        cin>>s;
        cout<<countPairs(root1, root2, s)<<"\n";
    }
    return 0;
}


// } Driver Code Ends


//User function Template for C++
/*Structure of the Node of the BST is as
struct Node {
	int data;
	Node* left, *right;
};*/
// You are required to complete this function
void inorder1(Node* root,map<int,bool>&m1){
    if(root==NULL){
        return;
    }
    inorder1(root->left,m1);
    m1[root->data]=true;
    inorder1(root->right,m1);
}
void inorder2(Node* root,map<int,bool>&m2){
    if(root==NULL){
        return;
    }
    inorder2(root->left,m2);
    m2[root->data]=true;
    inorder2(root->right,m2);
}
int countPairs(Node* root1, Node* root2, int x)
{
    // Code here
    map<int,bool>m1;
    map<int,bool>m2;
    inorder1(root1,m1);
    inorder2(root2,m2);
    int count=0;
    for(auto it:m1){
        if(m2[(x-(it.first))]==true){
            count++;
        }
        
    }
    return count;
}