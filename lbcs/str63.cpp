
// Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ]
//  where 0 ≤ i ≤ j < len(S). Palindrome string: A string which reads the same backwards. More formally, 
//  S is palindrome if reverse(S) = S. Incase of conflict, return the substring which occurs first ( with the least starting index ).

// NOTE: Required Time Complexity O(n2).

#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s){
    int count=1;
    int start=0;
    int j;
    int k;
    for(int i=1;i<s.length();i++){
        //for odd length palindrom
        j=i-1;
        k=i+1;
        while(s[j]==s[k]&&j>=0&&k<s.length()){
            if((k-j+1)>count){
                count=k-j+1;
                start=j;

            }
            j--;
            k++;
        }
        //for even length palindrome
        j=i-1;
        k=i;
        while(s[j]==s[k]&&j>=0&&k<s.length()){
            if((k-j+1)>count){
                count=k-j+1;
                start=j;

            }
            j--;
            k++;
        }

        
    }
    string temp="";
    for(int i=start;i<=start+count-1;i++){
        temp+=s[i];
    }
    return temp;
    
}


int main() {
    
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        cout<<longestPalindrome(s)<<endl;
        
    }
	//code
	return 0;
}