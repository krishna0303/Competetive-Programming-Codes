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


string shortestPrefix(TrieNode*root,string s){
    TrieNode*temp=root;
    string s1="";
    int n=s.length();
    for(int i=0;i<n;i++){
        int idx=(s[i]-'a');
        if(temp->child[idx]==NULL||temp->prefixCnt==0){
            return s1;
        }
        s1+=s[i];
        if(temp->child[idx]->prefixCnt>1){
             temp=temp->child[idx];
        }else{
            return s1;
        }
        
        
        
        
        
      
        

        

    }
    

}



int main(){
    
  
    
  int n;
  cin>>n;
   vector<string>words;
   struct TrieNode *root = createTrie(' ');
   for(int i=0;i<n;i++){
       string s;
       cin>>s;
       words.push_back(s);
       insertTrie(root,s);
   }
    

    
    for(int i=0;i<n;i++){
        cout<<shortestPrefix(root,words[i])<<endl;
    }
    return 0;
    
}