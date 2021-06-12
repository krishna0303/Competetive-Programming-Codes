// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

 /*
 idea is to keep all elements in set and iterate over string remove current element from set
 and compare it with min value of set i.e first value of set if current value is greater than first value of set
 then we have to  swap their value on all the places where they are present and that is our final answer 
 and if do not find above condition satisfy then we have to return the same string as output
 
 */
class Solution{
public:
    string chooseandswap(string s){
        // Code Here
        set<char>s1;
        int n=s.length();
        string t=s;
        for(int i=0;i<n;i++){
            s1.insert(s[i]);
            
        }
        bool flag=false;
        char a;
        char b;
        for(int i=0;i<n;i++){
            s1.erase(s[i]);
            if(s1.empty()){
                flag=true;
                break;
            }
            a=s[i];
            b=*(s1.begin());
            // cout<<a<<" "<<b<<endl;
            
            if(b<a){
                break;
                
            }
            
            
        }
        if(!flag){
            for(int i=0;i<n;i++){
            if(s[i]==a){
                t[i]=b;
            }
            if(s[i]==b){
                t[i]=a;
            }
        }
            
        }
        
        
        return t;
    }
    
};


// { Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}
  // } Driver Code Ends