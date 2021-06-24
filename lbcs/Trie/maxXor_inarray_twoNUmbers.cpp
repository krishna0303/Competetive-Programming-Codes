// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;




typedef struct TrieNode{
    
    int data;
    TrieNode*child[2];
}TrieNode;

TrieNode* createTrie(int data){
    TrieNode*root=new TrieNode;
    root->data=data;
   
    for(int i=0;i<2;i++){
        root->child[i]=NULL;
    }
    return root;
}

void insertTrie(TrieNode*root,int n){
    TrieNode*temp=root;
    for(int i=31;i>=0;i--){
        if(n&(1<<i)){ 
             if(temp->child[1]==NULL){
                 temp->child[1]=createTrie(1);
             }
             temp=temp->child[1];
        }else{
            if(temp->child[0]==NULL){
                 temp->child[0]=createTrie(0);
             }
             temp=temp->child[0];

        }
        
    }
    
    
}

int MaxXorArray(TrieNode *root,int n){
    TrieNode*temp=root;
    int q=0;
    for(int i=31;i>=0;i--){
        if(n&(1<<i)){
            if(temp->child[0]!=NULL){
                q=q|(1<<i);
                temp=temp->child[0];
            }
            else{
                temp=temp->child[1];
            }
            

        }else{
            if(temp->child[1]!=NULL){
                q=q|(1<<i);
                temp=temp->child[1];
            }else{
                temp=temp->child[0];
            }

        }
        
    }
    return q;

}

int findMaxXor(int *arr,int n){
    TrieNode*root=createTrie(-1);

    for(int i=0;i<n;i++){
        insertTrie(root,arr[i]);
    }
    int max_xor=INT_MIN;
    for(int i=0;i<n;i++){
        max_xor=max(max_xor,MaxXorArray(root,arr[i]));
    }
    return max_xor;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n;
        cin>>n;
        int *arr=new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
    	cout<<findMaxXor(arr,n)<<endl;
    }
}
// } Driver Code Ends

