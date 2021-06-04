#include<bits/stdc++.h>
using namespace std;

/*
We have to follow the step to solve this problem, they are:
1. Build a Priority_queue or max_heap, pq that stores characters and their frequencies.
…… Priority_queue or max_heap is built on the bases of frequency of character.
2. Create a temporary Key that will used as the previous visited element ( previous element in resultant string. Initialize it { char = ‘#’ , freq = ‘-1’ }
3. While pq is not empty.
….. Pop an element and add it to result.
….. Decrease frequency of the popped element by ‘1’
….. Push the previous element back into the priority_queue if it’s frequency > ‘0’
….. Make the current element as previous element for the next iteration.
4. If length of resultant string and original, print “not possible”. Else print result.

*/

const int MAX_CHAR = 26; 
  
struct Key 
{ 
    int freq; // store frequency of character 
    char ch; 
  
    // function for priority_queue to store Key 
    // according to freq 
    bool operator<(const Key &k) const
    { 
        return freq < k.freq; 
    } 
}; 

class Solution {
public:
    string reorganizeString(string s) {
        int count[MAX_CHAR]={0};
        int n=s.length();
        for(int i=0;i<n;i++){
            count[s[i]-'a']++;
            
        }
        
        priority_queue<Key>q;
        
        for(char c='a';c<='z';c++){
            if(count[c-'a']){
                q.push(Key{count[c-'a'],c});
            }
        }
        string str="";
        
        
        
        Key prev{-1,'#'};
        while(!q.empty()){
            Key k=q.top();
            q.pop();
            str+=k.ch;
            
            if(prev.freq>0)
               {
                   q.push(prev);
               }
            (k.freq)--;
            prev=k;
        }
                 if(n!=str.length()){
                     return "";
                 }else{
                     return str;
                 }
                 
                 
       
        
    }
};

int main(){
    Solution obj=Solution();
    string s;
    cin>>s;
    string ans=obj.reorganizeString(s);
    cout<<ans<<endl;
    return 0;
}