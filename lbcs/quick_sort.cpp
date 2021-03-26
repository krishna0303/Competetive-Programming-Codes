#include<bits/stdc++.h>
using namespace std;

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;

}

int partition(int *arr, int low, int high){
    int count=0;
    for(int i=low+1;i<=high;i++){
        if(arr[i]<=arr[low]){
            count++;
        }
    }
    swap(arr[low],arr[low+count]);
    int i=0,j=high;
    int pivot=low+count;
    while(i<pivot && j>pivot){
        if(arr[i]<=arr[pivot]){
            i++;
        }else if(arr[j]>arr[pivot]){
            j--;
        }
        else{
            swap(arr[i],arr[j]);
        }
    }
    return pivot;

}

void QuickSortUtil(int *arr, int low, int high){
    if(low<high){
        int pivot=partition(arr,low,high);
        QuickSortUtil(arr,low,pivot);
        QuickSortUtil(arr,pivot+1,high);

    }

}
void quickSort(int *arr, int n){
   QuickSortUtil(arr,0,n-1);
}
int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Before Quick Sort:"<<"\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    quickSort(arr,n);
    cout<<"\nBefore Quick Sort:"<<"\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}