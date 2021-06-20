#include<bits/stdc++.h>
using namespace std;

//for better understanding watch code librarry video

int AssemblyLineProblem(int st1,int e1,int st2,int e2,int n,int s1[],int s2[],int cross1[],int cross2[]){
    s1[0]+=st1;
    s2[0]+=st2;
    for(int i=1;i<n;i++){
        s1[i]=min((s1[i-1]+s1[i]),(s2[i-1]+cross2[i]+s1[i]));
        s2[i]=min((s2[i-1]+s2[i]),(s1[i-1]+cross1[i]+s2[i]));
    }
    return min(s1[n-1]+e1,s2[n-1]+e2);
    

}

int main(){
    int n;
    cin>>n;
    int entry1,exit1,entry2,exit2;
    cin>>entry1>>exit1>>entry2>>exit2;
    int s1[n],s2[n];
    for(int i=0;i<n;i++){
        cin>>s1[i];
    }
    for(int i=0;i<n;i++){
        cin>>s2[i];
    }
    int cross1[n],cross2[n];
    for(int i=0;i<n;i++){
        cin>>cross1[i];
    }
    for(int i=0;i<n;i++){
        cin>>cross2[i];
    }

    

    cout<<AssemblyLineProblem(entry1,exit1,entry2,exit2,n,s1,s2,cross1,cross2)<<endl;

    
        
    
    return 0;
}