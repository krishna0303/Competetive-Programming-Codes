#include<bits/stdc++.h>
using namespace std;


bool isPalindrome(string s){
    int i=0,j=s.length()-1;
    while(i<=j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;

}
void solve(string s,string str){
    
    int n=s.length();
    if(n==0){
        cout<<str.substr(0,str.length()-1)<<endl;
    }
    string temp="";
    for(int i=0;i<n;i++){
        temp+=s[i];
        if(isPalindrome(temp)){
            solve(s.substr(i+1),str+temp+" ");
        }
        str=str.substr(0,str.length()-temp.length()-2); //here 2 is used to remove space of both sides of current temp
        

    }

}

int main(){

    string s;
    cin>>s;
    solve(s,"");
    return 0;
}