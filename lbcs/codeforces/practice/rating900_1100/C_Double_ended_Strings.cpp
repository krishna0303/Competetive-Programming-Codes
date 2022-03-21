#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        int n = a.length();
        int m = b.length();
        int maxCnt=INT_MIN;
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0||j==0){
                    dp[i][j]=0;
                }
                else if(a[i-1]==b[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                    maxCnt=max(maxCnt,dp[i][j]);
                }else{
                    dp[i][j]=0;
                }
            }
        }

        int ans = (n + m) - (2 * maxCnt);
        cout << ans << endl;
    }
    return 0;
}