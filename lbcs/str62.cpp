#include<bits/stdc++.h>
using namespace std;

string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        string temp="";
        string small=countAndSay(n-1);
        int count=1;
        int i;
        for(i=1;i<small.length();i++){
            if(small[i]==small[i-1]){
                count++;
                
            }else{
                temp=temp+to_string(count)+small[i-1];
                count=1;
            }
            
        }
        temp=temp+to_string(count)+small[i-1];
        return temp;
        
    }
    int main(){
        int n;
        cin>>n;
        cout<<countAndSay(n)<<endl;
        return 0;
    }