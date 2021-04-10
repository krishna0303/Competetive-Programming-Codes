// in this file all the functionality of linked list is given

#include<bits/stdc++.h>
using namespace std;

//1 basic code of inked list
struct Node{
    int data;
    Node *link;
};
Node *head=NULL;


//insert at beginning
void insertBeg(int d){
    Node *ptr=new Node();
    ptr->data=d;
    ptr->link=head;
    head=ptr;
}

//insert at end
void insertEnd(int d){
    Node *ptr=new Node();   //creating new node
    Node *temp=head;
    ptr->data=d;
    // ptr->link=temp->link->link;   use this line to create a loop in linked list
     ptr->link=NULL;
    
    if(head==NULL){           //if list is empty
        head=ptr;
    }else{                    //if list is not empty
        
    while(temp->link!=NULL){
        temp=temp->link;
    }
    temp->link=ptr;

    }
    
   
}
//delete from begening

void deleteBeg(){
    if(head==NULL){
        cout<<"Linked list is empty!\n";
        

    }else{
        Node *ptr=head;
        head=head->link;
        free(ptr);
    }
}

//delete from end
void deleteEnd(){
    Node *ptr,*prev;
    if(head==NULL){
        cout<<"Linked list is empty!\n";
        

    }else{
        // Node *ptr=head;
        // Node *temp=head;
        // while(temp->link->link!=NULL){
        //     temp=temp->link;

        // }
        // ptr=temp->link;
        // temp->link=NULL;
        // free(ptr);
        if(head->link==NULL){
            ptr=head;
            head=NULL;
            free(ptr);
        }else{
            ptr=head;
            while(ptr->link!=NULL){
                prev=ptr;
                ptr=ptr->link;
            }
            prev->link=NULL;
            free(ptr);
        }
    }
}


//program to print the middle element of linked list in one pass

//1st approach is to count the toatal elements in linkedlist let n and divide it by 2 to get the middle element 
// which is n/2. but this approach will take two pass one for count n and other for finding middle element by iterating
// till n/2.so this method will not be work

// 2nd approach is use of two pointers >basic idea is one pointer move by 1 and another pointer is moving by 2 value 
// so when slow pointer will reach at the mid of element then fast pointer will already reach to the end of linked list
// because it is increasing by 2 so it will traverse 2 times than slow pointer and reach the end.

// even: 1>2>3>4>5>6>7>8
// odd: 1>2>3>4>5>6>7>8>9


void printMiddle(){
    Node *slow,*fast;
    if(head==NULL){
        cout<<"Linked list is empty!\n";
    }else{
        slow=head;
        fast=head;
        while(fast!=NULL&&fast->link!=NULL){  //for even it will check fast->link!=NULL and for odd it willcheck link!=NULL.
            slow=slow->link;
            fast=fast->link->link;
        }

        cout<<"middle element is:"<<slow->data<<endl;
    }

}


//Reverse a linked list in c++

// head-->1>2>3>4>5>NULL     before reverse
// NULL<1<2<3<4<5--<head  after reverse

//to do reverse we have to reverse the direction of each node and as well as change the head value to lst node

void reversell(){
    Node *ptr,*temp,*temp2;
    if(head==NULL){
        cout<<"Linkedlist is empty!\n";
    }else{
        temp=head;   //storing address of node which has pointed by head
        ptr=head->link;  //storing address of next node so that we can move further
        head->link=NULL; //making NULL in first node addresss link part because it should be our last node after reversal
        while(ptr!=NULL){     //checking ptr i.e node is not equal to NULL i.e value of ptr is not NULL
            temp2=ptr->link;  //now storing next node address in temp2 because we have to assign previous node address in current node address part
            ptr->link=temp;   //assigning previous node address to the current node address part.
            temp=ptr;         //storing current node adress for the next node where we have to assign this adress in next node address bar.
            ptr=temp2;        //changing ptr to ptr->link i.e temp2 i.e storing next node adress
            
            

        }
        
        head=temp;   //finally assigning address of last node i.e curent node to the head pointer

    }

}

//Find if loop exist in linked list or not

//use two pointers slow and fast and if slow==fast then there is loop or if fast==NULL there is no loop

void isLoop(){
    Node *slow,*fast;
    slow=head;
    fast=head;
    bool flag=false;
    while(fast!=NULL&&fast->link!=NULL){
        slow=slow->link;          //increament by 1
        fast=fast->link->link;   //increament by 2
        if(slow==fast){           //if slow==fast i.e if pointing adress of slow and fast is same then there is loop
            cout<<"Loop Found!\n";
            flag=true;
            break;
        }
    }
    if(!flag){
        cout<<"Loop Not Found!"<<endl;
    }
    
}

//delete node using a given pointer- here a pointer is given of any node in the linked list we have to delete that
// node.

void deleteNode(Node *ptr){
    
    Node *prev,*next;
    Node *temp=head;
    while(temp->link!=ptr){
        temp=temp->link;
    }
    next=ptr->link;
    temp->link=next;
    free(ptr);

}



int main(){
    Node *ptr=new Node();
    ptr->data=2;
    ptr->link=NULL;
    head=ptr;


    insertBeg(4);
    insertEnd(3);
    insertBeg(1);
    insertEnd(6);
    // deleteEnd();
    // printMiddle();
    // reversell();
    isLoop();

    Node *temp=head;


    // while(temp!=NULL){
    //     cout<<temp->data<<" ";
    //     temp=temp->link;
    // }cout<<endl;

    return 0;
}




