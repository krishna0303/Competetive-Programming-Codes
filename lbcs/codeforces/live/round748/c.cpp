#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll *arr = new ll[k];
        for (int i = 0; i < k; i++)
        {
            cin >> arr[i];
        }
        vector<ll> v;
        for (int i = 0; i < k; i++)
        {
            v.push_back(n - arr[i]);
        }
        sort(v.begin(), v.end());
        ll sum = 0;
        ll count = 0;
        for (int i = 0; i < v.size(); i++)
        {
            sum += v[i];
            if (sum >= n)
            {
                break;
            }
            else
            {
                count += 1;
            }
        }
        cout << count << endl;
    }
    return 0;
}