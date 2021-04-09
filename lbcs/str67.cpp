/*
Given a binary string str of length N, the task is to find the maximum count of substrings str can be divided into 
such that all the substrings are balanced i.e. they have equal number of 0s and 1s. If it is not possible to split 
str satisfying the conditions then print -1.

Example:

Input: str = “0100110101”
Output: 4
The required substrings are “01”, “0011”, “01” and “01”.

Input: str = “0111100010”
Output: 3
*/

#include<bits/stdc++.h>
using namespace std;

int splitBinary(string s){
    int count=0;
    int n=s.length();
    int count1=0,count2=0;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            count1+=1;
            if(count1==count2){
                count+=1;
                count1=0;
                count2=0;

            }
        }else{
            count2+=1;
            if(count1==count2){
                count+=1;
                count1=0;
                count2=0;

            }

        }
    }
    if(count1==count2){
        return count;
    }else{
        return -1;
    }
    // return count;
}
int main(){

    string s;
    cin>>s;
    int ans=splitBinary(s);
    cout<<ans<<endl;



    return 0;

}
