

#include<bits/stdc++.h>
#include <string.h>
using namespace std;

void isRotation(string s1, string s2){
    string temp="";
    int index=0;
    char first=s1[0];
    for(int i=0;i<s2.length();i++){
        if(s2[i]==first){
            index=i;
        }
    }
    int i=index;
    while(i<s2.length()){
        temp=temp+s2[i];
        i++;
        
    }
    int j=0;
    while(j<index){
        temp=temp+s2[j];
        j++;
    }
    // cout<<temp<<endl;
    if(s1==temp){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
}

void isRotation1(string s1,string s2){
    string temp=s1+s1;
    int i=0;
    int j=0;
    int l1=temp.length();
    int l2=s2.length();
    int count=0;
    bool flag=false;
    while(i<l1&&j<l2){
        if(temp[i]==s2[j]){
            count++;
            // cout<<count<<endl;
            i++;
            j++;

        }else{
            if(count==l2){
                cout<<"true"<<endl;
                flag=true;
                break;
            }else{
                count=0;
                j=0;
                i++;
            }
        }
    }
    if(count==l2){
    cout<<"true"<<endl;
    }
    else if(flag==false){
        cout<<"false"<<endl;
    }

}
bool areRotations(string str1, string str2)
{
   /* Check if sizes of two strings are same */
   if (str1.length() != str2.length())
        return false;
  
   string temp = str1 + str1; 
//    char* p;
  
    // Find first occurrence of s2 in s1
    // p = strstr(temp, str2);
  return (temp.find(str2) != string::npos);
}


int main(){
    string s1,s2;
    cin>>s1>>s2;
    isRotation1(s1,s2);
    
    return 0;
}