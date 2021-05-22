#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        vector<int> even,odd;
        
        for(int i=0;i<(2*n);i++){
            int item;
            cin>>item;
            if(item%2==0){
                even.push_back(item);

            }else{
                odd.push_back(item);
            }
        }
        int count=0;
        for(int i=1;i<even.size();i+=2){
            cout<<even[i-1]<<" "<<even[i]<<"\n";
            count++;
            if(count==(n-1)){
                break;
            }


        }
        for(int i=1;i<odd.size();i+=2){
            if(count==(n-1)){
                break;
            }
            cout<<odd[i-1]<<" "<<odd[i]<<"\n";
            count++;
            


        }
        
    }



    return 0;

}