#include<bits/stdc++.h>
using namespace std;

bool ispar(string x)
    {
        stack<char>s;
        for(int i=0;i<x.length();i++){
            if(x[i]=='{'||x[i]=='('||x[i]=='['){
                s.push(x[i]);
            }else{
                if(s.empty()){   //if starting character is closing brackets then it will automatic retuyrn false
                    return false;
                }
                char curr=s.top();
                if(!s.empty()&&curr=='{' && x[i]=='}'){
                    s.pop();
                }else if(!s.empty()&&curr=='(' && x[i]==')')
                {
                    s.pop();
                }else if(!s.empty()&&curr=='[' && x[i]==']'){
                    s.pop();
                }
                
                else{
                    return false;
                }
            }
        }
        if(!s.empty()){
            return false;
        }
        return true;
        // Your code here
    }
int main() {
    string s;
    cin>>s;
    cout<<ispar(s)<<endl;
    return 0;
}   