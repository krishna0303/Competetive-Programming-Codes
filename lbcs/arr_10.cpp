// Given two arrays A and B of size N and M respectively. The task is to find union between these two arrays.
// Union of the two arrays can be defined as the set containing distinct elements from both the arrays.
// If there are repetitions, then only one occurrence of element should be printed in union.



//for union
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//    int n,m;
//    cin>>n>>m;
//    set<int>s;
//    for(int i=0;i<n;i++){
//        int a;
//        cin>>a;
//        s.insert(a);
//    }
//    for(int i=0;i<m;i++){
//        int a;
//        cin>>a;
//        s.insert(a);
//    }
//    //for count 
//    cout<<s.size()<<endl;

//    //for elements
//    set<int>::iterator it=s.begin();
//    for(it;it!=s.end();it++){
//        cout<<*it<<endl;
//    }



//     return 0;
// }

//for intersection

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//    int n,m;
//    cin>>n>>m;
//    vector<int>v;
//    unordered_set<int>s;
//    for(int i=0;i<n;i++){
//        int a;
//        cin>>a;
//        s.insert(a);
//    }
//    for(int i=0;i<m;i++){
//        int a;
//        cin>>a;
//        if(s.find(a)!=s.end()){
//            v.push_back(a);
//        }
//    }
//    //for size
//    cout<<v.size()<<endl;
//    //for elements
//    for(int i=0;i<v.size();i++){
//        cout<<v[i]<<" ";
//    }
//    cout<<endl;







//     return 0;
// }

//Binary search method

bool BS(int *arr, int start, int end,int n){
    while(start<=end){
        int mid=(start+end)/2;
        if(arr[mid]==n){
            return true;
        }else if(n>arr[mid]){
            start=mid+1;
        }else{
            end=mid-1;
        }
    }
    return false;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
   int n,m;
   cin>>n>>m;
   int*arr=new int[n];
   for(int i=0;i<n;i++){
       cin>>arr[i];
   }
    int*b=new int[m];
   for(int i=0;i<m;i++){
       cin>>b[i];
   }
   vector<int>uni;
   vector<int>inter;
   if(n<=m){
       sort(arr,arr+n);
        for(int i=0;i<n;i++){
            uni.push_back(arr[i]);
        }
        for(int i=0;i<m;i++){
            if(BS(arr,0,n-1,b[i])){
                inter.push_back(b[i]);
            }else{
                uni.push_back(b[i]);
            }
        }

   }else{
        sort(b,b+m);
        for(int i=0;i<m;i++){
            uni.push_back(b[i]);
        }
        for(int i=0;i<n;i++){
            if(BS(b,0,m-1,arr[i])){
                inter.push_back(arr[i]);
            }else{
                uni.push_back(arr[i]);
            }
        }

   }
   //for UNION
    cout<<"Size of union is:"<<uni.size()<<"\n";
   for(int i=0;i<uni.size();i++){
       cout<<uni[i]<<" ";   
       
   }
   cout<<endl;
   //for Intersection
    cout<<"Size of intersection is:"<<inter.size()<<"\n";
   for(int i=0;i<inter.size();i++){
       cout<<inter[i]<<" ";   
       
   }
   cout<<endl;










    return 0;
}
