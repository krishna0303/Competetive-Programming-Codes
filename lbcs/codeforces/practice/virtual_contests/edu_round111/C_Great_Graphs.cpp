#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll *arr = new ll[n];
        for (int i = 0; i <n; i++)
        {
            cin >> arr[i];
        }
        sort(arr,arr+n);

        ll count = arr[n-1];
        ll neg[n];
        neg[0]=0;
        for(int i=1;i<n;i++){
            neg[i]=neg[i-1]+i*(arr[i]-arr[i-1]);
            count-=neg[i];
        }

        
        cout << count << endl;
    }

    return 0;
}