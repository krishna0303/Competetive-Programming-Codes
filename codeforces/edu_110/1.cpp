#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n=s.length();
        int*dp=new int[n];
        for(int i=0;i<n;i++){
            dp[i]=1;
        }
        for(int i=1;i<n;i++){
            int count=0;
            char s1=(s[i]);
            for(int j=i-1;j>=0;j--){
                if(s[j]!=s1||(s[j]==s1&&s1=='?')){

                    count+=1;
                    if(s[j]!='?'){
                        s1=s[j];
                    }else{
                        if(s1=='1'){
                            s1='0';
                        }else if(s1=='0'){
                            s1='1';
                        }

                    }

                    

                }else{
                    break;
                }
            }
            dp[i]+=dp[i-1];
            dp[i]+=count;
        }
        // for(int i=0;i<n;i++){
        //     cout<<dp[i]<<" ";
        // }cout<<endl;
        cout<<dp[n-1]<<endl;

        
    }

    return 0;
}