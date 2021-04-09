// Print all subsequences of a string

#include<bits/stdc++.h>
using namespace std;
void printAllSubsequences(string s,string output){
    if(s.length()==0){
        cout<<output<<endl;
    }
    else{
        printAllSubsequences(s.substr(1),output);
        printAllSubsequences(s.substr(1),output+s[0]);
    }
}
int main(){
    string s;
    cin>>s;
    string output="";
    printAllSubsequences(s,output);

    return 0;
}