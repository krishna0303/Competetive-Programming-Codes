#include<bits/stdc++.h>
using namespace std;
  


typedef struct TrieNode{
    char data;
    int wordEnd;
    TrieNode *child[26];
    
}TrieNode;

TrieNode* createTrie(char data){
    TrieNode *root=new TrieNode;
    root->data=data;
    root->wordEnd=0;
    for(int i=0;i<26;i++){
        root->child[i]=NULL;
    }
    return root;

}

void insertTrie(TrieNode*root,string s){
    
    TrieNode *temp=root;
    for(int i=0;i<s.length();i++){
        
        int idx=(s[i]-'a');
        if(temp->child[idx]==NULL){
            temp->child[idx]=createTrie(s[i]);

        }
        temp=temp->child[idx];
        
    }
    temp->wordEnd+=1;


}
bool findTrie(TrieNode*root,string s){
    TrieNode*temp=root;
    int n=s.length();
    for(int i=0;i<n;i++){
        
        int idx=(s[i]-'a');
        
        if(temp->child[idx]!=NULL){
            temp=temp->child[idx];
        }else{
            return false;
        }

        

    }
    if(temp!=NULL&&temp->wordEnd>0){
        return true;
    }else{
        return false;
    }


}

void deleteTrie(TrieNode*root,string s){
    TrieNode*temp=root;
    int n=s.length();
    for(int i=0;i<n;i++){
        int idx=(s[i]-'a');
        
        if(temp->child[idx]!=NULL){
            temp=temp->child[idx];
        }else{
            return;
        }

    }
    temp->wordEnd-=1;


}

int main(){
    
  
    struct TrieNode *root = createTrie(' ');
  
   
    insertTrie(root, "abc");
    insertTrie(root, "ab");
    insertTrie(root, "bca");
    insertTrie(root, "cab");
    insertTrie(root, "c");
    
    cout<<findTrie(root, "abc")<<endl;
    deleteTrie(root,"abc");
    cout<<findTrie(root, "abc")<<endl;
    return 0;
    
}