#include<bits/stdc++.h>
using namespace std;
struct minHeap{
    char data;
    int freq;
    minHeap*left;
    minHeap*right;
};
struct compare {
 
    bool operator()(minHeap* l, minHeap* r)
 
    {
        return (l->freq > r->freq);
    }
};

minHeap* createMinHeap(char data,int n ){
    minHeap* root=new minHeap();
    root->data=data;
    root->freq=n;
    root->left=root->right=NULL;
    return root;

}

void printHuffmanEncoding(minHeap*root,string str)
{
    if(!root){
        return;
    }
    if(root->data!='$'){
        cout<<root->data<<" : "<<str<<endl;
    }
    printHuffmanEncoding(root->left,str+"0");
    printHuffmanEncoding(root->right,str+"1");
    
}

void huffman_encoding(char *arr,int *freq,int n){
    minHeap*left,*right,*top;
    priority_queue<minHeap*,vector<minHeap*>,compare> pq;
    for(int i=0;i<n;i++){
        pq.push(createMinHeap(arr[i],freq[i]));
    }
    while(pq.size()!=1){
        left=pq.top();
        pq.pop();
        right=pq.top();
        pq.pop();
        top=createMinHeap('$',left->freq+right->freq);
        top->left=left;
        top->right=right;
        pq.push(top);
    }
    printHuffmanEncoding(pq.top(),"");
}

int mian(){
    // char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    // int freq[] = { 5, 9, 12, 13, 16, 45 };
 
    // int size = sizeof(arr) / sizeof(arr[0]);
    int n;
    cin>>n;

    char*arr=new char[n];
    int *freq=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i]>>freq[i];
    }
 
    huffman_encoding(arr, freq, n);



    return 0;
}