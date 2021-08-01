#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*

The essential difference between the set and the multiset is that in a set the keys must be unique, 
while a multiset permits duplicate keys. ... In both sets and multisets, the sort order of components is the sort order of the keys,
 so the components in a multiset that have duplicate keys may appear in any order.

 for better understanding of approach watch this https://www.youtube.com/watch?v=F5zq_BU25Ac

 here idea is to assign first m minimum numbers in each or m column for that we have used multiset which return minimum value
 and after that remaining element can be assign in any order

*/

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        ll **arr = new ll *[n];
        multiset<pair<ll, ll>> mst;
        for (int i = 0; i < n; i++)
        {
            arr[i] = new ll[m];
            for (int j = 0; j < m; j++)
            {
                arr[i][j] = -1;
                int x;
                cin >> x;
                mst.insert({x, i});
            }
        }
        for (int i = 0; i < m; i++)
        {
            auto itr = mst.begin();
            arr[itr->second][i] = itr->first;
            mst.erase(itr);
        }
        while (!mst.empty())
        {
            auto itr = mst.begin();
            int in = 0;
            while (arr[itr->second][in] != -1)
            {
                in++;
            }
            arr[itr->second][in] = itr->first;
            mst.erase(itr);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}