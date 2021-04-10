
// You are given a linked list of N nodes. Remove the loop from the linked list, if present. 
// Note: X is the position of the node to which the last node is connected to. If it is 0, then there is no loop.
// Input:
// N = 3
// value[] = {1,3,4}
// X = 2
// Output: 1
// Explanation: The link list looks like
// 1 -> 3 -> 4
//      ^    |
//      |____|    
// A loop is present. If you remove it 
// successfully, the answer will be 1.

//Algorithm
// This method is also dependent on Floyd’s Cycle detection algorithm.
// Detect Loop using Floyd’s Cycle detection algorithm and get the pointer to a loop node.
// Count the number of nodes in loop. Let the count be k.
// Fix one pointer to the head and another to a kth node from the head.
// Move both pointers at the same pace, they will meet at loop starting node.
// Get a pointer to the last node of the loop and make next of it as NULL.





// { Driver Code Starts
// driver code

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node* head)
{
    if(!head) return false;
    
    Node* fast = head->next;
    Node* slow = head;
    
    while( fast != slow)
    {
        if( !fast || !fast->next ) return false;
        fast=fast->next->next;
        slow=slow->next;
    }
    
    return true;
}

int length(Node* head)
{
    int ret = 0;
    while(head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}


 // } Driver Code Ends
/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/
#include<bits/stdc++.h>

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
         Node *slow,*fast;
        slow=head;
        fast=head;
        bool flag=false;
        while(fast!=NULL&&fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                flag=true;
                break;
            }
            
        }
        if(flag){
            // Count the number of nodes in loop
            int k=1;
            fast=fast->next;
            while(fast!=slow){  
                k++;
                fast=fast->next;
            }

            slow=head;    // Fix one pointer to head
            // And the other pointer to k nodes after head
            fast=head;
            for(int i=0;i<k;i++){
                fast=fast->next;
            }

            /*  Move both pointers at the same pace,
      they will meet at loop starting node */
            while(fast!=slow){
                fast=fast->next;
                slow=slow->next;
            }

             // Get pointer to the last node
            while(fast->next!=slow){
                fast=fast->next;
            }
            /* Set the next node of the loop ending node
      to fix the loop */
            fast->next=NULL;
            
            
            
            
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        ob.removeLoop(head);
        
        if( isLoop(head) || length(head)!=n )
            cout<<"0\n";
        else
            cout<<"1\n";
    }
	return 0;
}
  // } Driver Code Ends