#include<bits/stdc++.h>
using namespace std;

bool isValid(int n){
    if(n%10==3){
        return false;
    }
    int sum=0;
    while(n!=0){
        sum+=(n%10);
        n/=10;

    }
    if(sum%3==0){
        return false;
    }else{
        return true;
    }


}
int main(){
    int t;
    cin>>t;
    while(t--){
        int k;
        cin>>k;
        int count=0;
        int i=1;
        while(true){
            if(isValid(i)){
                count+=1;
                if(count==k){
                    break;
                }
            }
            i++;

        }
        cout<<i<<endl;
    }
    return 0;
}