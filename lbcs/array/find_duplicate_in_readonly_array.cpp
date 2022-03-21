
#include <bits/stdc++.h>
using namespace std;

int repeatedNumber(const vector<int> &A) {
    //pigenhole principle bucket
    // int interval=(A.size()-1)/(A.size()-1);
    // map<int,bool>m;
    // for(int i=0;i<A.size();i++){
    //     int val=(A[i]-1)/interval;
    //     if(!m[val]){
    //         m[val]=true;
    //     }else{
    //         return A[i];
    //     }
    // }

    //this solution is for wirtebale array but here array is read only
    // int n=A.size();
    // for(int i=0;i<A.size();i++){
    //     A[A[i]%n]+=n;

    // }
    // for(int i=0;i<n;i++){
    //     if(A[i]/n>1){
    //         return i;
    //     }
    // }

    int slow=A[0];
    int fast=A[A[0]];
    while(slow!=fast){
        slow=A[slow];
        fast=A[A[fast]];
    }
    if(slow==fast){
        fast=0;
        while(slow!=fast){
            slow=A[slow];
            fast=A[fast];
        }
        return slow;

    }else{
        return -1;
    }
}
