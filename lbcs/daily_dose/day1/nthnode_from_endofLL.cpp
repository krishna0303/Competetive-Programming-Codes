// { Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node* head, int n);



/* Driver program to test above function*/
int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n>>k;
        int firstdata;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }

    cout<<getNthFromLast(head, k)<<endl;
    }
    return 0;
}// } Driver Code Ends


/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
struct Node* reverseLL(struct Node *head){
    if(!head){
        return head;
    }
     struct Node *temp,*prev,*next,*ptr;
     
    
     ptr=head->next;
     head->next=NULL;
     prev=head;
     
     
     while(ptr!=NULL){
         temp=ptr->next;
         ptr->next=prev;
         prev=ptr;
         ptr=temp;
         
         
     }
     
     return prev;
     
     
     
     
}
int getNthFromLast(struct Node *head, int n)
{
    struct Node *temp,*prev,*next,*ptr;
    if(head==NULL){
        return -1;
    }
    ptr=reverseLL(head);
    int val=0;
    int count=0;
    while(ptr!=NULL){
        count+=1;
        val=ptr->data;
        // cout<<ptr->data<<" ";
        if(count==n){
            
            break;
        }
        ptr=ptr->next;
        
        
    }
    if(count==n){
        return val;
    }else{
        return -1;
    }
    
    
}
//Function to find the data of nth node from the end of a linked list.


