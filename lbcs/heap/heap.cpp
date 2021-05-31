


#include<bits/stdc++.h>
using namespace std;



typedef struct Heap{
    int *arr;
    int heap_size;
    int capacity;
}heap;

//returning parent of any index or node
int parent(int i){
    return (i-1)/2;
}
//left child of any index or node
int leftChild(int i){
    return (2*i+1);
}

//right child of any index or node
int rightChild(int i){
    return (2*i+2);
}

//create heap
heap* createMaxHeap(int cap){
    heap* h=new heap();
    if(!h){
        return NULL;
    }
    h->capacity=cap;
    h->heap_size=0;
    h->arr=new int[cap];
    if(!h->arr){
        return NULL;
    }
    return h;
}
//Inserting a new node into heap
void insertVal(heap* h,int val){
    if(h->heap_size>=h->capacity){
        cout<<"Array is overflow!"<<endl;
    }
    h->heap_size++;
    int i=h->heap_size-1;
    h->arr[i]=val;

    while(i!=0&&(h->arr[parent(i)])<(h->arr[i])){
        int temp=h->arr[parent(i)];
        h->arr[parent(i)]=h->arr[i];
        h->arr[i]=temp;
        i=parent(i);
    }
}

//this function is used to set or update any node to some new_val
// this is helpful for deleting any node first of all we will change that node value to INT_MAX
// so when it heapify it will automatically go to root of the tree and heap always delete root node
void IncreaseVal(heap*h, int i,int new_val){
   h->arr[i]=new_val;
   while(i!=0&&(h->arr[parent(i)]<h->arr[i])){
       int temp=h->arr[parent(i)];
       h->arr[parent(i)]=h->arr[i];
       h->arr[i]=temp;
       i=parent(i);
   }
}


//heapify  for delete operations i.e after deletions
void maxHeapify(heap*h,int i){
    int l=leftChild(i);
    int r=rightChild(i);
    int max=i;
    if(l<h->heap_size&&h->arr[l]>h->arr[i]){
        max=l;
    }
    if(r<h->heap_size&&h->arr[r]>h->arr[max]){
        max=r;
    }
    if(max!=i){
        int temp=h->arr[i];
        h->arr[i]=h->arr[max];
        h->arr[max]=temp;

        maxHeapify(h,max);
    }
    
}
//return max value which is at root node and delte it from tree and return 
int ExtractMax(heap*h){
    if(h->heap_size<=0){
        return INT_MIN;
    }
    if(h->heap_size==1){
        h->heap_size--;
        return h->arr[0];
    }
    int temp=h->arr[0];
    h->arr[0]=h->arr[h->heap_size-1];
    h->heap_size--;
    maxHeapify(h,0);
    return temp;
}

//for deleting
int deleteNode(heap*h,int i){
    IncreaseVal(h,i,INT_MAX);
    return ExtractMax(h);
}

//return maximum value without deleting any node
int getMax(heap*h){
    return h->arr[0];
}






int main(){

       
heap* h=createMaxHeap(7);
    insertVal(h,4);
    insertVal(h,8);
    insertVal(h,9);
    insertVal(h,12);
    insertVal(h,1);
    
    cout <<ExtractMax(h) << " ";
    cout << getMax(h) << " ";
   IncreaseVal(h,2,INT_MAX);
    cout << getMax(h);





    return 0;
}