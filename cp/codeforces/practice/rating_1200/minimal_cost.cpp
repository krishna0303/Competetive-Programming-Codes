#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
 so here  idea is to go one by ome in row and check obstcale column for current row and next row if both column are same then we have two possibility there
 1st is to move one obstacle right to thier current position and other obstacle left to their current possition and and their cost is v+v according to problem
2nd is to move one obstacle row wis e and thenc coulumn wise to cleear the path and its cost will be u+v

if both are not in same column and their coulmn diff is ==1 ther we have two choice we can perform min(u,v) i.e we can move one obstacle
columnwise or rowwise
if there coulm difference is greagter than 1 it means path is clear so don't have to move any obstacle and cost would become 0 store it and break because it would be or minimal cost
 */
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, u, v;
        cin >> n >> u >> v;
        ll *arr = new ll[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        ll ans = INT_MAX;

        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] == arr[i + 1])
            {
                ans = min(ans, min((u + v), (v + v)));
            }
            else if (abs(arr[i] - arr[i + 1]) == 1)
            {
                ans = min(ans, min(u, v));
            }
            else
            {
                ans = 0;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}