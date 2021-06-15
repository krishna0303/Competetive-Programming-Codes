// { Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

/*
my idea is to push first element into queue and set(it is used to search value in logn TC)page falut become 1
while i<n
check if that page is present in set or not if not present then go to else part and increase pageFault by 1 and there two condition first of all 
check queue size is less than c(i.e maximum capacity) or not, if it is less than maximum capacity then simply push that page into ques and set
if queue size is equal to size i.e c then we have to first of all remove front element from queue and from set and insert this new pages into queue as well as set

if the element is found into queue so we have to push all the elem to stack except that elemtn which is found
and after that transfer this stack elemnt to other stack to maintain the previous order of element in the queue now transfer
the element of second stack into queue and after all previous values inserted into queue insert this current page at the rear of queue




*/

class Solution{
public:
    int pageFaults(int n, int c, int pages[]){
        // code here
        queue<int>q;
        set<int>s;
        int i=0;
        // for(;i<c;i++){
        //     q.push(pages[i]);
        //     s.insert(pages[i]);
        // }
        int pageFault=1;
        q.push(pages[0]);
        s.insert(pages[0]);
        
        while(i<n){
            if(s.find(pages[i])!=s.end()){
                stack<int>st,st1;
                while(!q.empty()){
                    int val=q.front();
                    q.pop();
                    if(val!=pages[i]){
                        st.push(val);
                        
                    }
                    
                }
                while(!st.empty()){
                    int val=st.top();
                    st1.push(val);
                    st.pop();
                }
                while(!st1.empty()){
                    int val=st1.top();
                    q.push(val);
                    st1.pop();
                }
                q.push(pages[i]);
                
            }else{
                pageFault+=1;
                if(q.size()<c){
                    q.push(pages[i]);
                s.insert(pages[i]);
                    
                }else{
                    s.erase(q.front());
                q.pop();
                q.push(pages[i]);
                s.insert(pages[i]);
                    
                }
                
                
            }
            i++;
            
            
            
            
        }
        return pageFault;
        
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}  // } Driver Code Ends