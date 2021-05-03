/*

Given a stack, the task is to sort it such that the top of the stack has the greatest element.

Example 1:

Input:
Stack: 3 2 1
Output: 3 2 1
Example 2:

Input:
Stack: 11 2 32 3 41
Output: 41 32 11 3 2
*/


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */



/*algorithm to solve this problem is create another empty stack and swap that stack with orginal stack
then orginal stack will become empty and new stack become with value of orignal stack
now calculate the size of new stack and store it in n;
then apply for loop till n and call getMin function to get next minimum value and accordingly insert it into
original stack

*/

int getMin(stack<int>st1,int minVal1,int minVal2,int&handler,int prev){
    if(st1.empty()){
        return minVal1;    //return minimum value
    }else{
        int item=st1.top();
        st1.pop();
        //to handle occurence of same element
        if(item==minVal1){      
            prev=minVal1;  //
            handler+=1;
            // prev=minVal1;
        }else{
            if(prev!=minVal1){
                handler=1;
            }
        }
        //to handle next minimum value
        if(item<minVal1 &&item>minVal2){
            prev=minVal1;
            minVal1=item;
        }
        
        return getMin(st1,minVal1,minVal2,handler,prev);
        
        
    }
    
}
void SortedStack :: sort()
{
   //Your code here
   stack<int>st;
   st.swap(s);
   int n=st.size();
   map<int,int>m;
   
   int minVal2=INT_MIN;
   for(int i=0;i<n;){
       
       int minVal1=INT_MAX;
       int prev=INT_MIN;
       int handler=0;
       
       int ans=getMin(st, minVal1,minVal2,handler,prev);
       minVal2=ans;
       
    //   cout<<handler<<endl

    //handle occurence of same element
    int count =handler;
       while(handler>0){
           s.push(ans);
           handler--;
           
       }
       i+=(count-1)+1;
       
       
       
       
   }
//   cout<<s.size()<<endl;
   
   
   
}