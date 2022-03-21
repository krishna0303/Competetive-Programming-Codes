#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//https://codeforces.com/problemset/problem/1557/B

/*

idea is to sort the arerya and store it in another array and now compare count how many minimum subarray we can
form sot that we can sort the array by using given steps

*/
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll ans = 0;
        
        ans += max(6LL,n+1)/2 * 5;
        

        cout << ans << endl;
    }
}