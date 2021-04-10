
// A number N is represented in Linked List such that each digit corresponds to a
//  node in linked list. You need to add 1 to it

// Input:
// LinkedList: 4->5->6
// Output: 457 
// Example 2:

// Input:
// LinkedList: 1->2->3
// Output: 124


// { Driver Code Starts
//Initial template for C++


#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

// Reverse given linked list. For example, 1-> 9-> 9 -> 9 is converted to 9-> 9 -> 9 ->1.
// Start traversing linked list from leftmost node and add 1 to it. If there is a carry, move to the next node. Keep moving to the next node while there is a carry.
// Reverse modified linked list and return head.

class Solution
{
    public:
    Node*  reversell(Node *head){
    Node *ptr,*temp,*temp2;
    if(head==NULL){
        return head;
    }else{
        temp=head;   //storing address of node which has pointed by head
        ptr=head->next;  //storing address of next node so that we can move further
        head->next=NULL; //making NULL in first node addresss link part because it should be our last node after reversal
        while(ptr!=NULL){     //checking ptr i.e node is not equal to NULL i.e value of ptr is not NULL
            temp2=ptr->next;  //now storing next node address in temp2 because we have to assign previous node address in current node address part
            ptr->next=temp;   //assigning previous node address to the current node address part.
            temp=ptr;         //storing current node adress for the next node where we have to assign this adress in next node address bar.
            ptr=temp2;        //changing ptr to ptr->link i.e temp2 i.e storing next node adress
            
            

        }
        
        head=temp;   //finally assigning address of last node i.e curent node to the head pointer

    }
    return head;

}
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        Node *ptr,*temp,*temp1,*res,*prev=NULL;
        
        
        ptr=reversell(head);
        int carry=1;
        int val=0;
        res=ptr;
        
        while(ptr!=NULL&&carry>0){
            val=ptr->data+carry;
            if(val>9){
                ptr->data=val%10;
                carry=val/10;
                prev=ptr;
                ptr=ptr->next;
            }else{
                ptr->data=val;
                carry=0;
                prev=ptr;
                ptr=ptr->next;
                
                
            }
            
            
        }
        if(carry>0){
            Node *new_node = new Node(carry);
            // new_node->data = carry;
            // new_node->next = NULL;
            prev->next=new_node;
        }
        
        return reversell(res);
        
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends