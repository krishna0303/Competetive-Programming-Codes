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

bool isPowerOfTwo(int x)
{
    /* First x in the below expression is for the case when x is 0 */
    return x && (!(x & (x - 1)));
}
int main()

{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b;
        cin >> a >> b;
        long long ans = a;
        long long xo = 0;
        int n = 0;
        int temp=a;
        a = a - 1;
        if (a % 4 == 0)
        {
            n = a;
        }
        else if (a % 4 == 1)
        {
            n = 1;
        }
        else if (a % 4 == 2)
        {
            n = a + 1;
        }
        else if (a % 4 == 3)
        {
            n = 0;
        }
        if (n == b)
        {
            ans = ans;
        }else if((n^temp)==b){
            ans+=2;
        }
        else
        {
            ans += 1;
        }

        cout << ans << endl;
    }
    return 0;
}