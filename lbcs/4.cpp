

#include <bits/stdc++.h>

using namespace std;

bool compare(pair<int,int>&a,pair<int,int>&b){
    if(a.second>b.second){
        return true;
    }else{
        return false;
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        map<int,vector<int>>m;
        for(int i=0;i<n-1;i++){
            int x1,x2;
            cin>>x1>>x2;
            m[x1].push_back(x2);
            
        }
        map<int,vector<int>>::iterator it;
        for(it=m.begin();it!=m.end();it++){
            vector<pair<int,int>>v;
            for(int i=0;i<it->second.size();i++){
                int c=0;
                auto it2=m.find(it->second[i]);
                if(it2->first==it->second[i]){
                    c=it2->second.size();
                    
                }else{
                    c=0;
                }
                v.push_back({it->second[i],c});
            }
            sort(v.begin(),v.end(),compare);
            vector<int>v1;
            
            vector<pair<int,int>>::iterator it1;
            for(it1=v.begin();it1!=v.end();it1++){
                v1.push_back(it1->first);
                
            }
            it->second=v1;
        }
        map<int,int>data;
        for(int i=1;i<n+1;i++){
            auto it3=m.find(i);
            if(it3->first==i){
                int number=0;
                if(i==1){
                    number=x;
                    
                }else{
                    number=data.find(i)->second;
                    
                }
                int j=1;
                for(auto itr=it3->second.begin();itr!=it3->second.end();itr++){
                    data.insert({*itr,number*j});
                    j++;
                }
            }
        }
        int sum=x;
    
        for(auto itr=data.begin();itr!=data.end();itr++){
            sum+=itr->second;
            sum=sum%1000000007;
        }
        cout<<sum%1000000007<<endl;
        
    }
    

    return 0;
}
