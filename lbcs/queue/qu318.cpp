/*
Implement a Queue using 2 stacks s1 and s2 .
A Query Q is of 2 Types
(i) 1 x (a query of this type means  pushing 'x' into the queue)
(ii) 2   (a query of this type means to pop element from queue and print the poped element)
*/

// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

class StackQueue{
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int B);
    int pop();

};
int main()
{

    int T;
    cin>>T;
    while(T--)
    {
        StackQueue *sq = new StackQueue();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            sq->push(a);
        }else if(QueryType==2){
            cout<<sq->pop()<<" ";

        }
        }
        cout<<endl;
    }


}
// } Driver Code Ends


/* The structure of the class is
class StackQueue{
private:   
    // These are STL stacks ( http://goo.gl/LxlRZQ )
    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int pop();
}; */

//Function to push an element in queue by using 2 stacks.

//Algorithm

// method1(making push costly)
/*
element is always at the top of stack 1, so that deQueue operation just pops from stack1. To put the element at top of stack1, stack2 is used.

enQueue(q, x):



While stack1 is not empty, push everything from stack1 to stack2.
Push x to stack1 (assuming size of stacks is unlimited).
Push everything back to stack1.
Here time complexity will be O(n)

deQueue(q):

If stack1 is empty then error
Pop an item from stack1 and return it
Here time complexity will be O(1)

*/

// void StackQueue :: push(int x)
// {
//     // Your Code
    
//     while(!s1.empty()){
//         s2.push(s1.top());
//         s1.pop();
//     }
//     s1.push(x);
//     while(!s2.empty()){
//         s1.push(s2.top());
//         s2.pop();
//     }
// }

// //Function to pop an element from queue by using 2 stacks.
// int StackQueue :: pop()
// {
//         // Your Code 
//         if(s1.empty()){
//             return -1;
//         }else{
//             int item=s1.top();
//             s1.pop();
//             return item;
//         }
        
// }

//method2(making pop costly)

/*

enQueue(q,  x)
  1) Push x to stack1 (assuming size of stacks is unlimited).
Here time complexity will be O(1)

deQueue(q)
  1) If both stacks are empty then error.
  2) If stack2 is empty
       While stack1 is not empty, push everything from stack1 to stack2.
  3) Pop the element from stack2 and return it.
Here time complexity will be O(n)

*/
void StackQueue :: push(int x)
{
    // Your Code
    
    s1.push(x);
}

//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop()
{
        // Your Code 
        if(s1.empty()){
            return -1;
        }else{
            while(s1.size()!=1){
                s2.push(s1.top());
                s1.pop();
                
                
            }
            int item=s1.top();
            s1.pop();
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
            return item;
        }
        
}
