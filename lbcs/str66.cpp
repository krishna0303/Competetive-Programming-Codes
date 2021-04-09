// Print all permuation of a string

#include<bits/stdc++.h>
using namespace std;

// #method1 by using next_permutation library
// vector<string>find_permutation(string S)
// 		{
// 		    // Code here there
// 		    vector<string>v;
// 		    v.push_back(S);
// 		    sort(S.begin(),S.end());
// 		    while(next_permutation(S.begin(),S.end())){
// 		        v.push_back(S);
// 		    }
// 		    return v;
// }

void swap(char *x,char *y){
    char temp=*x;
    *x=*y;
    *y=temp;
}

void permute(string s,int l, int r,vector<string>&ans){
    if(l==r){
        ans.push_back(s);
    }else{
        for(int i=l;i<=r;i++){
            swap(s[l],s[i]);
            permute(s,l+1,r,ans);
            swap(s[l],s[i]);
        }
    }
}

vector<string>find_permutation(string s){
    vector<string>ans;
    int n=s.length();
    permute(s,0,n-1,ans);
    return ans;
    
    
    
}
int main(){
    string s;
    cin>>s;
    string output="";
    vector<string>ans=find_permutation(s);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    // printAllSubsequences(s,output);

    return 0;
}