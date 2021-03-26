#include<bits/stdc++.h>
using namespace std;


//First Aprroach by sorting method

void getCountSortMethod(int *arr,int n,int k){
    sort(arr,arr+n);
    int count=(n/k);
    int count1=1;
    for(int i=1;i<n;i++){
        
        if(arr[i]==arr[i-1]){
            count1+=1;
        }else{
            if(count1>count){
                cout<<arr[i-1]<<" ";
                
            }
            count1=1;
        }

    }
    if(count1>count){
                cout<<arr[n -1]<<" ";
                
            }
    cout<<endl;


}

//Second approach using hashmap

void getCountHashMap(int *arr, int n,int k){
    map<int,int>m;
    for(int i=0;i<n;i++){
        m[arr[i]]+=1;

    }
    int count=(n/k);
    map<int,int>::iterator it;
    for(it=m.begin();it!=m.end();it++){
        if(it->second>count){
            cout<<it->first<<" ";
        }
    }
    cout<<endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    getCountSortMethod(arr,n,k);
    getCountHashMap(arr,n,k);
    




    return 0;
}