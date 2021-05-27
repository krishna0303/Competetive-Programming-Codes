// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
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

void printAllDups(Node* root);

int main()
{
  int t;
  struct Node *child;
  scanf("%d\n", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d\n",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL) root = parent;
        }
        else parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')parent->left = child;
        else parent->right = child;
        m[n2]  = child;
     }
     printAllDups(root);
     cout<<endl;
  }
  return 0;
}// } Driver Code Ends


//function Template for C++

/*
Structure of the node of the binary tree is as
struct Node {
	int data;
	struct Node* left, *right;
};
*/
// you are required to complete this function
// the function should print all the root node of the
// duplicate subtree in non-decreasing order
// need not print a new line
string order(Node * root,unordered_map<string,int>&m,vector<int>&v){
    if(!root){
        return " ";
    }
    string str="(";
    str+=order(root->left,m,v);
    str+=to_string(root->data);
    str+=order(root->right,m,v);
    str+=")";
    if(m[str]==1){
        v.push_back(root->data);
    }
    m[str]++;
    return str;
}
void printAllDups(Node* root)
{
    // Code here
    unordered_map<string,int>m;
    vector<int>v;
    order(root,m,v);
    if(v.size()==0){
        cout<<-1<<endl;
    }else{
        reverse(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        
    }
}