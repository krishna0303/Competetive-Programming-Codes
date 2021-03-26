//Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

// If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

// The replacement must be in place and use only constant extra memory.


#include<bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& v) {
        int n=v.size();
        int index=-1;

    for(int i=n-2;i>=0;i--){
        if(v[i]<v[i+1]){
            index=i;
            int upper=index+1;
            int val=v[index+1];
            for(int j=n-1;j>index;j--){
                if(v[j]>v[index]){
                    if(val>v[j]){
                        val=v[j];
                        upper=j;
}
                }

            }
            swap(v[index],v[upper]);
            
            sort(v.begin()+index+1,v.end());
            
            break;
        }
            
    }
    if(index==-1){
        reverse(v.begin(),v.end());
    }
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }cout<<endl;
        
    };


int main(){
    vector<int>v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
        
    }
    nextPermutation(v);

    return 0;
}