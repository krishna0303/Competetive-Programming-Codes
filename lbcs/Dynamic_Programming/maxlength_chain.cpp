// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/
//sorting based on second value if second value is equal then sort using firat value in ascending order
bool compare(const struct val &a,const struct val &b){
    if(a.second==b.second){
        return a.first<b.first;
    }else{
        return a.second<b.second;
    }
}
//approach is similar to longest increasing subsqequences with some modification
int maxChainLen(struct val p[],int n)
{
    int dp[n];
    for(int i=0;i<n;i++){
        dp[i]=1;
    }
    sort(p,p+n,compare);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(p[j].second<p[i].first&&dp[i]<=dp[j]){
                dp[i]=1+dp[j];
            }
            
        }
    }
    return *max_element(dp,dp+n);


}