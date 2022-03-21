#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        deque<int> q;
        q.push_back(arr[0]);
        for (int i = 1; i < n; i++)
        {
            int top = q.front();
            if (arr[i] <= top)
            {
                q.push_front(arr[i]);
            }
            else
            {
                q.push_back(arr[i]);
            }
        }
        while (!q.empty())
        {
            int top = q.front();
            q.pop_front();
            cout << top << " ";
        }
        cout << endl;
    }
    return 0;
}