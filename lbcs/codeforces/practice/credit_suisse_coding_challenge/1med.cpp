#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef long long int ll;
ll totalPairs(ll n, vector<ll> &values)
{

    ll count = 0;
    for (ll i = 0; i < n; i++)
    {
        ll maxm = INT_MIN;
        bool flag = false;
        for (ll j = i + 1; j < n; j++)
        {
            if (values[j] < values[i])
            {
                if (values[j] > maxm)
                {

                    count += 1;
                    maxm = values[j];
                }
            }
            else
            {
                count += 1;

                break;
            }
        }
    }
    return count;

    // int count = n - 1;
    // int i = 0, j = 1;
    // while (i < n && j < n)
    // {
    //     if (values[i] > values[j])
    //     {
    //         int temp = values[j];
    //         j++;

    //         while (j < n)
    //         {
    //             if (temp < values[j])
    //             {
    //                 count += 1;
    //                 temp = values[j];
    //                 j++;
    //             }
    //             else
    //             {
    //                 i = j - 1;
    //                 break;
    //             }
    //         }
    //     }
    //     else
    //     {
    //         i++;
    //         j++;
    //     }
    // }
    // // i = n - 1;
    // // j = n - 2;
    // // int count1 = n - 1;
    // // while (i >= 0 && j >= 0)
    // // {
    // //     if (values[i] > values[j])
    // //     {
    // //         int temp = values[j];
    // //         j--;

    // //         while (j >= 0)
    // //         {
    // //             if (temp < values[j])
    // //             {
    // //                 count1 += 1;
    // //                 temp = values[j];
    // //                 j--;
    // //             }
    // //             else
    // //             {
    // //                 i = j+1;
    // //                 break;
    // //             }
    // //         }
    // //     }
    // //     else
    // //     {
    // //         i--;
    // //         j--;
    // //     }
    // // }
    // return count;
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> values(n);
    for (ll i = 0; i < n; ++i)
    {
        cin >> values[i];
    }
    ll answer = totalPairs(n, values);
    // Do not remove below line
    cout << answer << endl;
    // Do not print anything after this line

    return 0;
}
