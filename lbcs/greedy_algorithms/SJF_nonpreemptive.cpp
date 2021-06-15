#include<bits/stdc++.h>
using namespace std;

bool compare(const tuple<int,int,int>&a,const tuple<int,int,int>&b){
    if(get<1>(a)==get<1>(b)){
        if(get<0>(a)==get<0>(b)){
            return (get<2>(a)<get<2>(b));
        }else{
            return (get<0>(a)<get<0>(b));
        }
    }
    else{
        return (get<1>(a)<get<1>(b));
    }
        
}


void ShortestJobFirst(vector<tuple<int,int,int>>v,int n){
    sort(v.begin(),v.end(),compare);
    int completion[n]={0};
    int turnarround[n]={0};
    int waiting[n]={0};
    //priority queue first of all get minimum of burst time which is first value in tuple athen second value which is arrival time and then process id which is third value of tuple
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
    int currentTime=0;
    pq.push(v[0]);
    int i=1;//because we have pushed one process
    while(!pq.empty()){
        tuple<int,int,int>t=pq.top();
        pq.pop();

       
        currentTime+=get<0>(t);
        completion[get<2>(t)]=currentTime;
        turnarround[get<2>(t)]=currentTime-get<1>(t);
        waiting[get<2>(t)]=(currentTime-get<1>(t))-get<0>(t);
        int burst=get<0>(t);
        while(true){
            if(i<n&&get<1>(v[i])<=currentTime){   //checking all the process whose arrival time is smaller than currenttime
                                                  //and then inserting them into priority_queue and pq will return minimum burst time process first among all the process inside the pq
                pq.push(v[i]);
                i++;


            }else{    
                break;  //because we have sorted element in ascending order of arrival time so if smaller not satisfy then larger will also not satisfy above condition so it would be break
            }
        }



    }
    int avgwaitingtime=0,avgturnarroundtime=0;
    cout<<"Turnarround Time  Waiting Time"<<endl;
    for(int i=0;i<n;i++){
        cout<<turnarround[i]<<" "<<waiting[i]<<endl;
        avgturnarroundtime+=turnarround[i];
        avgwaitingtime+=waiting[i];
    }
    cout<<"Average TurnArround Time: "<<(double)avgturnarroundtime/(double)n<<"\n";
    cout<<"Average Waiting Time: "<<(double)avgwaitingtime/(double)n<<"\n";


    
        
}

int main(){
    int n;
    cin>>n;
    vector<tuple<int,int,int>>v;
    
    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
      
        v.push_back(make_tuple(c,b,a));
    }
    ShortestJobFirst(v,n);
    

    return 0;
}