


// Given a singly linked list consisting of N nodes. The task is to remove duplicates (nodes with duplicate values) 
// from the given list (if exists).
// Note: Try not to use extra space. Expected time complexity is O(N). The nodes are arranged in a sorted way.

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
    cout<<temp->data<<" ";
    temp=temp->next;
    }
}
Node* removeDuplicates(Node *root);
int main() {
	// your code goes here
	int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		Node *head = NULL;
        Node *temp = head;

		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		
		Node *result  = removeDuplicates(head);
		print(result);
		cout<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

//Function to remove duplicates from sorted linked list.


Node *removeDuplicates(Node *head)
{
 // your code goes here
 if(head->next==NULL){   //if linked has contain 1 value then return as it is.
     return head;
 }
 Node *ptr,*temp,*temp1,*prevtemp;
 ptr=head;  //assign head
 temp=head;    
 ptr=ptr->next;
 while(ptr!=NULL){
     
     
     if(temp->data!=ptr->data){ //if previoius node data and current node data are not same
         temp->next=ptr;        //then add address of current node to the address part of previous node which is stored in temp
         temp=ptr;               //after storing address of current node change the teamp to current node
         
         ptr=ptr->next;          //increament the ptr and move ahead
     }else{        //if if previoius node data and current node data are  same
         prevtemp=ptr;           //assign the current node address to prevtemp
         temp1=ptr->next; //assign next node address in temp1
         ptr=temp1;       //assign the value of ptr by temp1 it means ptr is pointing to the next node
     
         free(prevtemp);    //free current node which are similar to previous node data
         
         
         
         
         
     }
     
     
     
 }
 temp->next=NULL;
 return head;
 
}


//Function to remove duplicates from unsorted linked list.

 Node * removeDuplicates( Node *head) 
    {
     // your code goes here
     map<int,int>m;
     
      if(head->next==NULL){
     return head;
 }
 Node *ptr,*temp,*temp1,*prevtemp;
 ptr=head;
 temp=head;
//  prevtemp=head;
//  bool flag=false;
 m[temp->data]=1;
 ptr=ptr->next;
 while(ptr!=NULL){
     
     
     if(!m[ptr->data]){
         m[ptr->data]=1;
         temp->next=ptr;
         temp=ptr;
        //  flag=false;
         ptr=ptr->next;
         
     }else{
         prevtemp=ptr;
         temp1=ptr->next;
         ptr=temp1;
        //  flag=true;
         free(prevtemp);
         
         
         
         
         
     }
     
     
     
 }
 temp->next=NULL;
 return head;
    }