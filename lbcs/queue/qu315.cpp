//Implement a Stack using two queues q1 and q2.

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        QueueStack *qs = new QueueStack();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            qs->push(a);
        }else if(QueryType==2){
            cout<<qs->pop()<<" ";

        }
        }
        cout<<endl;
    }
}
// } Driver Code Ends


/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */

//Function to push an element into stack using two queues.





//method1 (making push operation costly)
// Algorithm

/*

This method makes sure that newly entered element is always at the front of ‘q1’, so that pop operation 
just dequeues from ‘q1’. ‘q2’ is used to put every new element at front of ‘q1’.

push(s, x) operation’s step are described below:
Enqueue x to q2
One by one dequeue everything from q1 and enqueue to q2.
Swap the names of q1 and q2
pop(s) operation’s function are described below:
Dequeue an item from q1 and return it.
*/

// void QueueStack :: push(int x)
// {
//         // Your Code
//         q2.push(x);
//         while(!q1.empty()){
//             int item=q1.front();
//             q2.push(item);
//             q1.pop();
//         }
//         q1.swap(q2);
        
// }

// //Function to pop an element from stack using two queues. 
// int QueueStack :: pop()
// {
//     if(q1.empty()){
//         return -1;
//     }
//     int item=q1.front();
//     q1.pop();
//     return item;
    
    
    
        
        
// }

//method2(making pop operation costly)

//Algorithm

/*

In push operation, the new element is always enqueued to q1. In pop() operation, if q2 is empty then all
 the elements except the last, are moved to q2. Finally the last element is dequeued from q1 and returned.

push(s, x) operation:
Enqueue x to q1 (assuming size of q1 is unlimited).
pop(s) operation:
One by one dequeue everything except the last element from q1 and enqueue to q2.
Dequeue the last item of q1, the dequeued item is result, store it.
Swap the names of q1 and q2
Return the item stored in step 2.



*/

void QueueStack :: push(int x)
{
        // Your Code
        q1.push(x);
        
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
    if(q1.empty()){
        return -1;
    }

    while(q1.size()!=1){
        q2.push(q1.front());
        q1.pop();
        
        
        
        
    }
    int temp=q1.front();
    q1.pop();
    q1.swap(q2);
    return temp;
    
    
    
        
        
}
