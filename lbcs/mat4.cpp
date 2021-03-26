#include<bits/stdc++.h>
using namespace std;

int findMax1(int**arr,int n, int m){
    int count=0;
	    int index=-1;
	    for(int i=0;i<n;i++){
	        int count1=0;
	        for(int j=0;j<m;j++){
	            if(arr[i][j]==1){
	                count1+=1;
	            }
	            
	        }
	        if(count1>count){
	            count=count1;
	            index=i;
	        }
	    }
	    return index;
}
int findMax2(int**arr,int n, int m){
    
	    int index=-1;
	    for(int i=0;i<m;i++){
	        
            bool flag=false;
	        for(int j=0;j<n;j++){
	            if(arr[j][i]==1){
                    index=j;
                    flag=true;
                    break;
	               
	            }
	            
	        }
            if(flag==true){
                break;
            }
	        
	    }
	    return index;
}
int main(){
    int r,c;
    cin>>r>>c;
    int **arr=new int*[r];
    for(int i=0;i<r;i++){
        arr[i]=new int[c];
        for(int j=0;j<c;j++){
            cin>>arr[i][j];
        }
    }

    cout<<findMax1(arr,r,c)<<endl;
    cout<<findMax2(arr,r,c)<<endl;




    return 0;
}