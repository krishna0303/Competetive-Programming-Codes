#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        int n=s.length();
        if(s[0]==s[n-1]){
            cout<<"NO"<<endl;
        }else{
            stack<char>st;
            char a=s[0];
            char b=s[n-1];
            bool flag=false;
            for(int i=0;i<n;i++){
                if(s[i]==a){
                    st.push(s[i]);

                }else if(s[i]==b){
                    st.pop();

                }else{
                   st.push(a);
                }
            }
            if(st.empty()){
                flag=true;
            }
            while(!st.empty()){
                st.pop();
            }
            for(int i=0;i<n;i++){
                if(s[i]==a){
                    st.push(s[i]);

                }else if(s[i]==b){
                    st.pop();

                }else{
                   st.pop();
                }
            }
            if(st.empty()){
                flag=true;
            }
            if(flag){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }

        }
        
    }
    
    return 0;
}