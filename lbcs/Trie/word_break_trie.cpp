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
bool wordBreak(TrieNode*root,string s){
    if(s.length()==0){
        return true;
    }

    string t="";
    for(int i=0;i<s.length();i++){
        t+=s[i];
        if(findTrie(root,t)&&wordBreak(root,s.substr(i+1))){
            return true;
            
        }

    }
    return false;

}





int main(){
    
  
    
  int n;
  cin>>n;
//    vector<string>words;
   struct TrieNode *root = createTrie(' ');
   for(int i=0;i<n;i++){
       string s;
       cin>>s;
    //    words.push_back(s);
       insertTrie(root,s);
   }
    

    string input;
    cin>>input;
    if(wordBreak(root,input)){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
    
    return 0;
    
}