// Given a string S consisting only of opening and closing curly brackets '{' and '}' find out
//  the minimum number of reversals required to make a balanced expression.

#include <bits/stdc++.h>
using namespace std;

int main() {
    
	int t;
	cin>>t;
	while(t--){
	    string x;
	    cin>>x;
	    int n=x.length();
	    int ans=0;
	    if(n%2==0){
	        stack<char>s;
	        for(int i=0;i<x.length();i++){
            if(x[i]=='{'){
                s.push(x[i]);
            }else{
                if(s.empty()){   //if starting character is closing brackets then it will automatic retuyrn false
                    s.push(x[i]);
                    
                }else{
                    char curr=s.top();
                    if(!s.empty()&&curr=='{' && x[i]=='}'){
                        s.pop();
                    
                    }
                    
                    else{
                        s.push(x[i]);
                    }
                }
            }
	        
	        
	        
	    }
	    if(!s.empty()){
	        
	    while(!s.empty()){
	        char current=s.top();
	        s.pop();
	        char curr=s.top();
	        s.pop();
	        if(current==curr){
	            ans+=1;
	        }else{
	            ans+=2;
	        }
	        
	    }
	        
	    }else{
	        ans=0;
	    }
	    }else{
	        ans=-1;
	    }
	    cout<<ans<<endl;
	    
	}
	
	return 0;
}