//idea to solve this problem is we can arrange all the elements in subarray in any order but can't take whole array as subarray
//
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int*arr=new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int count=0;
        bool flag=false;
        for(int i=0;i<n;i++){//if all elemnts are sorted then minimum count is 0.
            if(arr[i]!=(i+1)){
                flag=true;
                break;
            }
        }
        if(flag){//if not sorted
            if(arr[0]==(1)||arr[n-1]==(n)){  //if value at index 0 or last index if right value is present then we can take all subarray and except that element and sort the subarray i.e reaarange . Eg: 3 4 2 1 5 so in this example 5 is at right position so we can take subarray as 3 4 2 1 and rearrange them then 1 2 3 4 5 become sortyed steps require only 1.
                count=1;
            }else if(arr[0]==n&&arr[n-1]==1){  //if element is completely reverse then we neede three count EG:5 4 3 2 1 first of all we will take subarray->5 1 2 3 4->1 2 3 5 4->1 2 3 4 5
                count=3;
            }else{//else count is 2
                count=2;
            }

        }
        cout<<count<<endl;
    }
    return 0;
}