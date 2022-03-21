#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MN=4e5+2;
ll arr[MN];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        ll count = 0;
        // arr[0]=0;
        arr[n + 1] = 0;
        for (int i = 1; i <= n; i++)
        {
            ll will = min(arr[i], max(arr[i - 1], arr[i + 1]));
            count += ((arr[i] - will) + abs(will - arr[i - 1]));
            arr[i] = will;
        }
        count += arr[n];

        cout << count << endl;
    }
    return 0;
}