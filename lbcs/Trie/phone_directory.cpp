// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

/*

idea is to store the index of that particular string at each prefix of that particular string with prefixcnt
whichever string has the same prefix push the index of that string in data vector
so during finding we got the vector of index which has the given prefix as input
and then we can simply print all the index value of contact



*/

typedef struct TrieNode{
        vector<int> data;
        int prefixcnt;
        TrieNode*child[26];
    }TrieNode;
    
class Solution{
public:
    
    TrieNode* CreateTrie(int idx){
        TrieNode *root=new TrieNode;
        root->data.push_back(idx);
        root->prefixcnt=1;
        for(int i=0;i<26;i++){
            root->child[i]=NULL;
        }
        return root;
    }
    
    void insertTrie(TrieNode *root, string s,int index){
        int n=s.length();
        TrieNode *temp=root;
        for(int i=0;i<n;i++){
            int idx=(s[i]-'a');
            if(temp->child[idx]==NULL){
                temp->child[idx]=CreateTrie(index);
            }else{
                temp->child[idx]->data.push_back(index);
                temp->child[idx]->prefixcnt+=1;
            }
            temp=temp->child[idx];
        }
        
    }
    
    bool findTrie(TrieNode *root,string s,vector<int>&index){
        int n=s.length();
        TrieNode *temp=root;
        for(int i=0;i<n;i++){
            int idx=(s[i]-'a');
            if(temp->child[idx]==NULL){
                return false;
            }
            temp=temp->child[idx];
        }
        if(temp!=NULL&&temp->prefixcnt>0){
            index=temp->data;
            
            return true;
        }else{
            return false;
        }
        
        
    }
    
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        int m=s.length();
        TrieNode *root=CreateTrie(-1);
        for(int i=0;i<n;i++){
            insertTrie(root,contact[i],i);
            
        }
       vector<vector<string>>ans;
       string temp="";
       
       for(int i=0;i<m;i++){
           vector<string>v;
           vector<int>index;
           set<string>st;
           temp+=s[i];
           if(findTrie(root,temp,index)){
               for(int j=0;j<index.size();j++){
                //   cout<<index[j]<<" ";
                   if(st.find(contact[index[j]])==st.end()){
                       st.insert(contact[index[j]]);
                       v.push_back(contact[index[j]]);
                   }
                   
               }
               sort(v.begin(),v.end());
               
           }else{
               v.push_back("0");
           }
           
           
        //   v.push_back("\n");
           ans.push_back(v);
           
       }
       return ans;
        
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends