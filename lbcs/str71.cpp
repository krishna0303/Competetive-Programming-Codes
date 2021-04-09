/*
Given a string A and a dictionary of n words B, find out if A can be segmented 
into a space-separated sequence of dictionary words. 
*/
#include<bits/stdc++.h>
using namespace std;


int wordBreak(string A, vector<string> &B) {
    //code here
    // map<string,int>m;
    // for(int i=0;i<B.size();i++){
    //     m[B[i]]=B[i].length();
    // }
    set<string>s;
    for(int i=0;i<B.size();i++){
        s.insert(B[i]);
    }
    string temp="";
    for(int i=0;i<A.length();i++){
        temp+=A[i];
        if(s.find(temp)!=s.end()){
            temp="";
        }
    }
    if(temp==""){
        return 1;
        
    }else{
        return 0;
    }
}


int main(){

    string s;
    cin>>s;
    vector<string>v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string temp;
        cin>>temp;
        v.push_back(temp);
    }

    int ans=wordBreak(s,v);
    cout<<ans<<endl;



    return 0;

}
