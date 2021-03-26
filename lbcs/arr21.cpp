
// Given an array of integers. Find the Inversion Count in the array. 

// Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. 
// If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum. 
// Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.


#include<bits/stdc++.h>
using namespace std;

int merge(int *arr, int start, int mid, int end){
    int i=start,j=mid+1;
    int k=start;
    // int a[end-start+1];
    vector<int>v;
    int countInv=0;
    while(i<=mid&&j<=end){
        if(arr[i]>arr[j]){
            countInv+=((mid-i)+1);
            v.push_back(arr[j]);
            j++;



        }else{
            v.push_back(arr[i]);
            i++;

        }

    }
    while(i<=mid){
        v.push_back(arr[i]);
        i++;
    }
    while(j<=end){
        v.push_back(arr[j]);
        j++;
    }
    for(int i=0;i<v.size();i++){
        arr[k]=v[i];
        k++;
        // cout<<v[i]<<" ";
    }
    // cout<<endl;
    return countInv;
}

void mergeSort(int *arr,int start, int end, int &countInv){
    
    if(start<end){
        int mid=(start+end)/2;
        mergeSort(arr,start,mid,countInv);
       mergeSort(arr,mid+1,end,countInv);
        countInv+=merge(arr,start,mid,end);

        // return x+y+z;
    }
    
}

void countInversion(int *arr, int n){
    int start=0;
    int end=n-1;
    int countInv=0;
    mergeSort(arr, start,end,countInv);
    cout<<countInv<<endl;
}
int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];

    }

    countInversion(arr,n);
    return 0;
}

//GeegksForgeekscode
// { Driver Code Starts
// #include <bits/stdc++.h>
// using namespace std;


//  // } Driver Code Ends
// class Solution{
    
//     long long int merge(long long *arr, long long start, long long mid, long long end){
//     long long i=start,j=mid+1,k=start;
    
//     // int a[end-start+1];
//     vector<long long>v;
//     long long int countInv=0;
//     while(i<=mid&&j<=end){
//         if(arr[i]>arr[j]){
//             countInv+=((mid-i)+1);
//             v.push_back(arr[j]);
//             j++;



//         }else{
//             v.push_back(arr[i]);
//             i++;

//         }

//     }
//     while(i<=mid){
//         v.push_back(arr[i]);
//         i++;
//     }
//     while(j<=end){
//         v.push_back(arr[j]);
//         j++;
//     }
//     for(long long i=0;i<v.size();i++){
//         arr[k]=v[i];
//         k++;
//         // cout<<v[i]<<" ";
//     }
//     // cout<<endl;
//     return countInv;
// }

// void mergeSort(long long *arr,long long start, long long end, long long int &countInv){
    
//     if(start<end){
//         long long mid=(start+end)/2;
//         mergeSort(arr,start,mid,countInv);
//        mergeSort(arr,mid+1,end,countInv);
//         countInv+=merge(arr,start,mid,end);

//         // return x+y+z;
//     }
    
// }
    
    
//   public:
//     // arr[]: Input Array
//     // N : Size of the Array arr[]
//     // Function to count inversions in the array.
//     long long int inversionCount(long long arr[], long long N)
//     {
//         // Your Code Hereint start=0;
//     long long start=0;
//     long long end=N-1;
//      long long int countInv=0;
//     mergeSort(arr, start,end,countInv);
//     return countInv;
//     // cout<<countInv<<endl;
//     }

// };

// // { Driver Code Starts.

// int main() {
    
//     long long T;
//     cin >> T;
    
//     while(T--){
//         long long N;
//         cin >> N;
        
//         long long A[N];
//         for(long long i = 0;i<N;i++){
//             cin >> A[i];
//         }
//         Solution obj;
//         cout << obj.inversionCount(A,N) << endl;
//     }
    
//     return 0;
// }
//   // } Driver Code Ends