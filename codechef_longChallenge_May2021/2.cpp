#include<bits/stdc++.h>
using namespace std;
 int main(){
     int t;
     cin>>t;
     while(t--){
         char arr[3][3];
         int count1=0,count2=0,count3=0,winner1=0,winner2=0;
         for(int i=0;i<3;i++){
             for(int j=0;j<3;j++){
                 cin>>arr[i][j];
                 if(arr[i][j]=='X'){
                     count1+=1;
                 }else if(arr[i][j]=='O'){
                     count2+=1;
                 }else if(arr[i][j]=='_'){
                     count3+=1;
                 }
             }

         }

         for(int i=0;i<3;i++){
             if(arr[0][i]==arr[1][i]&&arr[2][i]==arr[1][i]){
                 if(arr[0][i]=='X'){
                     winner1+=1;
                 }else if(arr[0][i]=='O'){
                     winner2+=1;
                 }

             }
         }
         for(int i=0;i<3;i++){
             if(arr[i][0]==arr[i][1] && arr[i][2]==arr[i][1]){
                 if(arr[i][0]=='X'){
                     winner1+=1;
                 }else if(arr[i][0]=='O'){
                     winner2+=1;
                 }
                 
                 
             }
         }

         if(arr[0][2]==arr[1][1]&&arr[1][1]==arr[2][0]){
             if(arr[1][1]=='X'){
                     winner1+=1;
                 }else if(arr[1][1]=='O'){
                     winner2+=1;
                 }

         }

         if(arr[0][0]==arr[1][1]&&arr[1][1]==arr[2][2]){
             if(arr[1][1]=='X'){
                     winner1+=1;
                 }else if(arr[1][1]=='O'){
                     winner2+=1;
                 }

         }
        //  int ans;

        //  cout<<count1<<" "<<count2<<" "<<winner1<<" "<<winner2<<" "<<count3<<endl;

         if(count2>count1||(count1-count2)>1){
            //  ans=3;
            cout<<3<<endl;
         }else if((count1>count2&&winner1==1&&winner2==0)||(count1==count2&&winner1==0&&winner2==1)){
            //  ans=1;
            cout<<1<<endl;
         }else if((count3==0&&winner2==0&&winner1==2)||(count3==0&&(winner1+winner2==0))){
            //  ans=1;
            cout<<1<<endl;
         }
         else if(count3>0&&(winner1+winner2==0)){
            //  ans=2;
            cout<<2<<endl;
         }else{
            //  ans=3;
            cout<<3<<endl;
         }

        //  cout<<ans<<endl;




     }



     return 0;

 }