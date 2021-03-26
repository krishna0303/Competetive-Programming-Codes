//Given two sorted arrays arr1[] of size N and arr2[] of size M. Each array is sorted in non-decreasing order. 
//Merge the two arrays into one sorted array in non-decreasing order without using any extra space.

// 1 


#include<bits/stdc++.h>
using namespace std;


// void merge(int *arr1, int*arr2, int n,int m){
//     for(int i=m-1;i>=0;i++){
       
//             int last=arr1[n-1];
//             int j;
//             for (j = m - 2; j >= 0 
//              && arr1[j] > arr2[i]; j--){
            
//                 arr1[j+1]=arr1[j];
//                 j--;
//             }
//             if(j!=n-2 || last>arr2[i]){

//              arr1[j+1]=arr2[i];
//             arr2[i]=last;
//             }
            
        
//     }
// }
// void merge(int ar1[], int ar2[], int m, int n)
// {
//     // Iterate through all elements 
//     // of ar2[] starting from the last element
//     for (int i = n - 1; i >= 0; i--) 
//     {
//         /* Find the smallest element greater than ar2[i].
//         Move all elements one position ahead till the
//         smallest greater element is not found */
//         int j, last = ar1[m - 1];
//         for (j = m - 2; j >= 0 
//              && ar1[j] > ar2[i]; j--)
//             ar1[j + 1] = ar1[j];
 
//         // If there was a greater element
//         if (j != m - 2 || last > ar2[i]) 
//         {
//             ar1[j + 1] = ar2[i];
//             ar2[i] = last;

//         }
//     }
// }


int nextGap(int gap){
    if(gap<=1){
        return 0;
    }
    return (gap/2)+(gap%2);
}

void merge(int *arr1,int *arr2,int n,int m){
    int i,j,gap=n+m;
    for(gap=nextGap(gap);gap>0;gap=nextGap(gap)){
        //for checking first array
        for(i=0;i+gap<n;i++){
            if(arr1[i]>arr1[i+gap]){
                swap(arr1[i],arr1[i+gap]);
            }
        }
        //checking for both the arrays
        for(j=gap>n?gap-n:0; i<n && j<m;i++,j++){
            if(arr1[i]>arr2[j]){
                swap(arr1[i],arr2[j]);
            }
        }
        if(j<m){
            for(j=0;j+gap<m;j++){
                if(arr2[j]>arr2[j+gap]){
                    swap(arr2[j],arr2[j+gap]);
                }
            }
        }

    }
    
}

int main(){
    int n,m;
    cin>>n>>m;
    int *arr1=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    int *arr2=new int[m];
    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }
    
    merge(arr1,arr2,n,m);
    for(int i=0;i<n;i++){
        cout<<arr1[i]<<" ";
    }
    for(int i=0;i<m;i++){
        cout<<arr2[i]<<" ";
    }
    cout<<endl;







   


    return 0;
}