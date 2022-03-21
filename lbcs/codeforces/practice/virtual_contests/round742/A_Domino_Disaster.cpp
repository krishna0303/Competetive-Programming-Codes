// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int t;
//     cin>>t;
//     while(t--){

//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'L' || s[i] == 'R')
            {

                ans += s[i];
            }
            else if (s[i] == 'U')
            {
                ans += 'D';
            }
            else
            {
                ans += 'U';
            }
        }
        cout << ans << endl;
    }
    return 0;
}