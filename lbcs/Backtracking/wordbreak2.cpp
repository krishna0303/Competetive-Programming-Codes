// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

void wordBreakUtil(map<string,bool>m, string s,vector<string>&ans,string str){
    if(s.length()==0){
        ans.push_back(str.substr(0,str.length()-1));
        return ;
    }
    string temp="";
    for(int i=0;i<s.length();i++){
        temp+=s[i];
        if(m[temp]){
            str+=temp;
            wordBreakUtil(m,s.substr(i+1,s.length()),ans,str+" ");
            str=str.substr(0,str.length()-temp.length());
            
        }
        
        
    }
}
class Solution{
public:
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        vector<string>ans;
        map<string,bool>m;
        for(int i=0;i<n;i++){
            m[dict[i]]=true;
        }
        wordBreakUtil(m,s,ans,"");
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends