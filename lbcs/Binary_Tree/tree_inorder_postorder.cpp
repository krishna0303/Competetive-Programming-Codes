// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

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


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
int indx=0;
unordered_map<int,int>m;
Node *construct(int in[],int pre[], int low,int high){
    if(low>high){
        return NULL;
    }
    Node *res=new Node(pre[indx++]);
    if(low==high){
        return res;
    }
    int mid=m[res->data];
    res->left=construct(in,pre,low,mid-1);
    res->right=construct(in,pre,mid+1,high);
    return res;
}
class Solution{
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code 
        indx=0;
        m.clear();
        for(int i=0;i<n;i++){
            m[in[i]]=i;
        }
        Node* res=construct(in,pre,0,n-1);
    return res;
    } 
    
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends