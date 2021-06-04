// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


 // } Driver Code Ends
//User function Template for C++
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
void insertNode(vector<int>&heap,int val){
    heap.push_back(val);
    int i=heap.size()-1;
    while(i!=0&&heap[parent(i)]<heap[i]){
        swap(heap[parent(i)],heap[i]);
        i=parent(i);
    }
}

void heapify(vector<int>&heap,int n,int i){
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

class Solution
{
    public:

    //Using heap stl
    /*
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        vector<int>heap;
        for(int i=0;i<K;i++){
            for(int j=0;j<K;j++){
                heap.push_back(arr[i][j]);
            }
        }
        make_heap(heap.begin(),heap.end());
        sort_heap(heap.begin(),heap.end());
        return heap;
        
    }
    
    */
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        vector<int>heap;
        for(int i=0;i<K;i++){
            for(int j=0;j<K;j++){
                insertNode(heap,arr[i][j]);
            }
        }
        int n=heap.size();
        for(int i=n-1;i>0;i--){
            swap(heap[0],heap[i]);
            heapify(heap,i,0);
            
        }
        return heap;
        
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(N, vector<int> (N, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}





  // } Driver Code Ends