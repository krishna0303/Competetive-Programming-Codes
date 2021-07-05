#include<bits/stdc++.h>
using namespace std;

void solve(int n,string s){
    int arr[26]={0};
    for(int i=0;i<n;i++){
        arr[s[i]-'a']+=1;
    }
    for(int i=0;i<26;i++){
        if(arr[i]==0){
            cout<<char('a'+i)<<endl;
            return;
        }
    }
    set<string>s1;
    for(int i=0;i<n-1;i++){
        string temp="";
        temp+=s[i];
        temp+=s[i+1];
        s1.insert(temp);
    }
    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
            string temp="";
            temp+=char('a'+i);
            temp+=char('a'+j);
            if(s1.find(temp)==s1.end()){
                cout<<temp<<endl;
                return;
            }
        }
    }
    set<string>s2;
    for(int i=0;i<n-2;i++){
        string temp="";
        temp+=s[i];
        temp+=s[i+1];
        temp+=s[i+2];
        s2.insert(temp);
    }
    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
            string temp="a";
            temp+=char('a'+i);
            temp+=char('a'+j);
            if(s2.find(temp)==s2.end()){
                cout<<temp<<endl;
                return;
            }
        }
    }


}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        solve(n,s);
        

    }
    return 0;
}