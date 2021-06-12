#include<bits/stdc++.h>
using namespace std;

/*
A board of length m and width n is given, we need to break this board in
to m*n squares such that cost of breaking is minimum. cutting cost for each edge 
will be given for the board. In short, we need to choose such 
a sequence of cutting such that cost is minimized. 

For above board optimal way to cut into square is:
Total minimum cost in above case is 42. It is 
evaluated using following steps.

Initial Value : Total_cost = 0
Total_cost = Total_cost + edge_cost * total_pieces

Cost 4 Horizontal cut         Cost = 0 + 4*1 = 4
Cost 4 Vertical cut        Cost = 4 + 4*2 = 12
Cost 3 Vertical cut        Cost = 12 + 3*2 = 18
Cost 2 Horizontal cut        Cost = 18 + 2*3 = 24
Cost 2 Vertical cut        Cost = 24 + 2*3 = 30
Cost 1 Horizontal cut        Cost = 30 + 1*4 = 34
Cost 1 Vertical cut        Cost = 34 + 1*4 = 38
Cost 1 Vertical cut        Cost = 38 + 1*4 = 42

to clear the concepts watch code library video for better understanding of this problem

*/


int main(){

    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        n--;
        m--;
        int x[m],y[n];
        for(int i=0;i<m;i++)cin>>x[i];
        for(int i=0;i<n;i++)cin>>y[i];
        sort(x,x+m,greater<int>());
        sort(y,y+n,greater<int>());

        int ans=0;
        int verticalCnt=1;
        int horizontalCnt=1;
        int i=0,j=0;
        while(i<m&&j<n){
            if(x[i]>y[j]){
                ans+=(x[i]*verticalCnt);
                horizontalCnt++;
                i++;
            }else{
                ans+=(y[j]*horizontalCnt);
                verticalCnt++;
                j++;
            }
        }
        while(i<m){
            ans+=(x[i]*verticalCnt);
            i++;
        }
        while(j<n){
            ans+=(x[j]*horizontalCnt);
            j++;
        }
        cout<<ans<<endl;

        


    }
    return 0;
}