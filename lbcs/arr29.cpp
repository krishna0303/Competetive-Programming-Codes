// Given an array of positive integers. Find the length of the longest sub-sequence such that elements
//  in the subsequence are consecutive integers,
//  the consecutive numbers can be in any order.


#include<bits/stdc++.h>
using namespace std;
int findLongestConseqSubseq(int arr[], int n)
    {
      //Your code here
      map<int,bool>m;
        for(int i=0;i<n;i++){
            m[arr[i]]=true;
        }
        int maxCount=0;
        int maxM=INT_MIN;
        int minM=INT_MAX;
        for(int i=0;i<n;i++){
            if(arr[i]>maxM){
                maxM=arr[i];
            }
            if(arr[i]<minM){
                minM=arr[i];
            }


        }
        
        for(int i=0;i<n;i++){
            int count1=0;
            if(m[arr[i]]){
                
                count1=1;
                int temp=arr[i];
                
                m[arr[i]]=false;
                temp++;
                while(m[temp]){
                    m[temp]=false;
                    count1++;
                    temp++;
                    

                    // if(m[temp]){
                    //     count1+=1;
                    //     m[temp]=false;
                    // }else{
                    //     break;
                    // }

                }
                temp=arr[i];
                temp--;
                while(m[temp]){
                    count1+=1;
                    m[temp]=false;
                    temp--;
                    // if(m[temp]){
                    //     count1+=1;
                    //     m[temp]=false;
                    // }else{
                    //     break;
                    // }

                }
            }
            if(count1>maxCount){
                maxCount=count1;
            }

        }
        return maxCount;
    }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<findLongestConseqSubseq(arr,n)<<endl;
    return 0;
}