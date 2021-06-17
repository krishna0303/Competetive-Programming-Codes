

//Using Trie

// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
vector<vector<string> > Anagrams(vector<string>& string_list) ;

 // } Driver Code Ends
//User function Template for C++

typedef struct TrieNode{
    int group;
    int wordEnd;
    TrieNode*child[26];
}TrieNode;

TrieNode* createTrie(){
    TrieNode*root=new TrieNode;
    root->wordEnd=0;
    root->group=0;
    for(int i=0;i<26;i++){
        root->child[i]=NULL;
    }
    return root;
}

void insertTrie(TrieNode*root,string s,int groupid){
    TrieNode*temp=root;
    for(int i=0;i<s.length();i++){
        int idx=(s[i]-'a');
        if(temp->child[idx]==NULL){
            temp->child[idx]=createTrie();
        }
        temp=temp->child[idx];

    }
    temp->wordEnd+=1;
    temp->group=groupid;
}

bool findTrie(TrieNode *root,string s,int &id){
    TrieNode*temp=root;
    for(int i=0;i<s.length();i++){
        int idx=(s[i]-'a');
        if(temp->child[idx]==NULL){
            return false;
        }
        temp=temp->child[idx];

    }
    if(temp!=NULL&&temp->wordEnd>0){
         id=temp->group;
        return true;

    }else{
        return false;
    }

}



vector<vector<string> > Anagrams(vector<string>& string_list) 
{
    // Your Code Here
    vector<vector<string>>ans;
    
    TrieNode*root=createTrie();
    int maxGroups=0;
    int n=string_list.size();
    for(int i=0;i<n;i++){
        string temp=string_list[i];
        sort(temp.begin(),temp.end());
        int groupid;
        if(!findTrie(root,temp,groupid)){
            insertTrie(root,temp,maxGroups);
            maxGroups+=1;

        }
        
    }
    vector<string>v[maxGroups];
    for(int i=0;i<n;i++){
        string temp=string_list[i];
        sort(temp.begin(),temp.end());
        int groupid;
        if(findTrie(root,temp,groupid)){
            v[groupid].push_back(string_list[i]);
            

        }
    }
    // cout<<maxGroups<<endl;
    for(int i=0;i<maxGroups;i++){
        vector<string>v1;
        // cout<<v[i].size()<<endl;
        for(int j=0;j<v[i].size();j++){
            v1.push_back(v[i][j]);

        }
        ans.push_back(v1);
    }
    
    return ans;
    
    
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        vector<vector<string> > result = Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
  // } Driver Code Ends

//Without using Trie this solution uses map

// { Driver Code Starts
// //Initial Template for C++
// #include <bits/stdc++.h>
// #include <unordered_map>
// using namespace std;
// vector<vector<string> > Anagrams(vector<string>& string_list) ;



// vector<vector<string> > Anagrams(vector<string>& string_list) 
// {
//     // Your Code Here
//     vector<vector<string>>ans;

//     map<string,vector<string>>m;
//     int maxGroups=0;
//     int n=string_list.size();
//     for(int i=0;i<n;i++){
//         string temp=string_list[i];
//         sort(temp.begin(),temp.end());
        
//         m[temp].push_back(string_list[i]);
//     }
//     for(auto it:m){
//         vector<string>v;
//         for(int i=0;i<it.second.size();i++){
//             v.push_back(it.second[i]);
            
//         }
//         ans.push_back(v);
//     }
//     return ans;
    
    
// }

// { Driver Code Starts.

// int main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         int n;
//         cin>>n;
//         vector<string> string_list(n);
//         for (int i = 0; i < n; ++i)
//             cin>>string_list[i]; 
//         vector<vector<string> > result = Anagrams(string_list);
//         sort(result.begin(),result.end());
//         for (int i = 0; i < result.size(); i++)
//         {
//             for(int j=0; j < result[i].size(); j++)
//             {
//                 cout<<result[i][j]<<" ";
//             }
//             cout<<"\n";
//         }
//     }

//     return 0;
// }
  // } Driver Code Ends