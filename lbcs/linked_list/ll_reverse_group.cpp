//Given a linked list of size N. The task is to reverse every k nodes 
// (where k is an input to the function) in the linked list.

// LinkedList: 1->2->2->4->5->6->7->8
// K = 4
// Output: 4 2 2 1 8 7 6 5 
// Explanation: 
// The first 4 elements 1,2,2,4 are reversed first 
// and then the next 4 elements 5,6,7,8. Hence, the 
// resultant linked list is 4->2->2->1->8->7->6->5.

// Input:
// LinkedList: 1->2->3->4->5
// K = 3
// Output: 3 2 1 5 4 
// Explanation: 
// The first 3 elements are 1,2,3 are reversed 
// first and then elements 4,5 are reversed.Hence, 
// the resultant linked list is 3->2->1->5->4.




// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


 // } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    
    struct node *reverse (struct node *head, int k)
    { 
        node *ptr,*temp,*temp2,*header,*current,*prevcurrent;
        current=NULL;   //storing current value is NULL
        prevcurrent=head;   //storing prevcurrent =head
        temp=NULL;   //storing NULL 
        ptr=head;  //storing address first node
        
        int count=0;
       
        while(ptr!=NULL ){     //checking ptr i.e node is not equal to NULL i.e value of ptr is not NULL
            temp2=ptr->next;  //now storing next node address in temp2 because we have to assign previous node address in current node address part
            ptr->next=temp;   //assigning previous node address to the current node address part.
            temp=ptr;         //storing current node adress for the next node where we have to assign this adress in next node address bar.
            ptr=temp2;        //changing ptr to ptr->link i.e temp2 i.e storing next node adress
            count+=1;         //increament count by 1
            if(count==k){     //checking condition if count==k i.e group of elemnts which we have to reverse we found out
                if(current==NULL){  //if current value is NULL it means this is first group which we have reversed so we are assigning its last elemtn address to header and it will be the final head after reversal
                    header=temp;   //assigning temp value to header which is the last elemenmt of first group
                    current=temp2;  //changing current value to first value of next group
                }else{            // above if condition fails it means it is not the first group i.e it is intermediate or last group
                    prevcurrent->next=temp;   //so here we have to store last element of current group to the first element of previous group
                    prevcurrent=current;     //here changing the prevcurrent to current which store the first element of this current group
                    current=temp2;          //accordingly storing first value of next group
                }
                count=0;                  //making count=0 for next group
                
            }

        }
        if(count!=0){           //if count!=0 it means ourlast group is less than k i.e let say k=4 and count =2 but loop termianted due to rich ptr==NULL so we have to reverse this two nodes as well
            prevcurrent->next=temp;   //so here we have to store last element of current group to the first element of previous group
        prevcurrent=current;           //here changing the prevcurrent to current which store the first element of this current group
        prevcurrent->next=ptr;          //inserting null which is stored in ptr==NULL to the first eleemnt of current group
        }else{        //here count==0 it means all the group has already reversed there is no go group left so we have to insert only NULL to the last of reversed linked list
            prevcurrent->next=ptr;      //inserting null to the cureent group first element next part i.e in address bar
        }
        
        
           //finally assigning address of last node i.e curent node to the head pointer

        return header;   //returning header which is head of reversed linked list
        
    }
    
};


// { Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}

  // } Driver Code Ends