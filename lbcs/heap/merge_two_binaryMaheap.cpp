
/*
Given two binary max heaps as arrays, merge the given heaps, after merging the two arrays.
The task is very simple to merge the two arrays firstly keep all the elements of first array than 
elements second array, than apply the merge operation of heaps.

 

Example 1:

Input  : 
n = 4 m = 3
a[] = {10, 5, 6, 2}, 
b[] = {12, 7, 9}
Output : 
{12, 10, 9, 2, 5, 7, 6}
*/



// { Driver Code Starts
// Initial Template for C++



// C++ program to merge two max heaps.
#include <bits/stdc++.h>
using namespace std;

void mergeHeaps(int merged[], int a[], int b[], int n, int m);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        int a[n], b[m];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (i = 0; i < m; i++) {
            cin >> b[i];
        }
        int merged[m + n];
        mergeHeaps(merged, a, b, n, m);

        for (int i = 0; i < n + m; i++) cout << merged[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


// User function Template for C++
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
void heapify(int heap[],int n,int i){
    int l=leftChild(i);
    int r=rightChild(i);
    int max=i;
    if(l<n&&heap[l]>heap[i]){
        max=l;
    }
    if(r<n&&heap[r]>heap[max]){
        max=r;
    }
    if(max!=i){
        swap(heap[i],heap[max]);
        heapify(heap,n,max);
    }
}
void buildHeap(int merged[],int n){
    for(int i=(n/2-1);i>=0;i--){
        heapify(merged,n,i);
    }
}

void mergeHeaps(int merged[], int a[], int b[], int n, int m) {
    int i=0;
    for(;i<n;i++){
        merged[i]=a[i];
    }
    for(int j=0;j<m;j++,i++){
        merged[i]=b[j];
    }
    buildHeap(merged,n+m);
}