

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a=n/9;
        int b=n%9;
        
        int n1=9;
        string s="";
        int count=0;
        for(int i=0;i<a;i++){
            s+=to_string(n1);
            count+=i;
            n1-=1;
        }
        b+=count;
        bool flag=false;
        if(b>0&&b<=n1){
            s+=to_string(b);
        }else{
            while(b!=0){
                if((b-n1)>=0){
                   s+=to_string(n1);
                   b-=n1;
                   n1--;
                }else{
                    n1--;
                }
                if(n1<=0&&b!=0){
                    flag=true;
                    break;
                }
                

            }
        }
        reverse(s.begin(), s.end());
        int val=stoi(s);
        if(flag){
            cout<<-1<<endl;
        }else{
            cout<<val<<endl;
        }


        
        
        
    }

    return 0;
}
