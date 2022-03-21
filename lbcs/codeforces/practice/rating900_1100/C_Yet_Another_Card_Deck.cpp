#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{

    ll n, q;
    cin >> n >> q;
    ll *arr1 = new ll[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    ll *arr2 = new ll[q];
    for (int i = 0; i < q; i++)
    {
        cin >> arr2[i];
    }
    vector<pair<ll, ll>> v;
    map<ll, bool> m;
    vector<ll> ans;
    for (int i = 0; i < n; i++)
    {
        if (!m[arr1[i]])
        {
            v.push_back({arr1[i], i + 1});
            m[arr1[i]] = true;
        }
    }
    for (int i = 0; i < q; i++)
    {
        int index = 0;
        for (int j = 0; j < v.size(); j++)
        {
            if (v[j].first == arr2[i])
            {
                ans.push_back(v[j].second);
                index = j;
                v[j].second = 1;
            }
        }
        pair<ll, ll> p = v[index];
        index = index - 1;
        while (index >= 0)
        {
            v[index].second += 1;
            v[index + 1] = v[index];
            index--;
        }
        v[0] = p;
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}