#include<bits/stdc++.h>
using namespace std;
  


typedef struct TrieNode{
    char data;
    int prefixCnt;
    TrieNode *child[26];
    
}TrieNode;

TrieNode* createTrie(char data){
    TrieNode *root=new TrieNode;
    root->data=data;
    root->prefixCnt=1;
    
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

        }else{
            temp->child[idx]->prefixCnt+=1;
        }
        temp=temp->child[idx];
        
    }
    


}


int prefixCount(TrieNode*root,string s){
    TrieNode*temp=root;
    
    int n=s.length();
    for(int i=0;i<n;i++){
        int idx=(s[i]-'a');
        if(temp->child[idx]==NULL||temp->prefixCnt==0){
            return 0;
        }
        temp=temp->child[idx];
        
        
        
        
      
        

        

    }
    return temp->prefixCnt;
    

}



int main(){
    
  
    struct TrieNode *root = createTrie(' ');
  
   
    insertTrie(root, "abc");
    insertTrie(root, "ab");
    insertTrie(root, "bca");
    insertTrie(root, "cab");
    insertTrie(root, "c");
    
    cout<<prefixCount(root, "b")<<endl;
    cout<<prefixCount(root, "the")<<endl;
    cout<<prefixCount(root, "c")<<endl;
    
    cout<<prefixCount(root, "ab")<<endl;
    return 0;
    
}