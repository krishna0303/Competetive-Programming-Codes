

#include <bits/stdc++.h>
using namespace std;

/*




A conveyor belt has packages that must be shipped from one port to another within B days.

The ith package on the conveyor belt has a weight of A[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within B days.



Problem Constraints
1 <= B <= |A| <= 5 * 105
1 <= A[i] <= 105


Input Format
First argument is array of integers A denoting the weights.

Second argument is the integer B denoting the number of days.



Output Format
Return the least weight capacity of the ship.


Example Input
Input 1:
A = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
B = 5
Input 2:

A = [3, 2, 2, 4, 1, 4]
B = 3


Example Output
Ouput 1:
15
Ouput 2:

6


Example Explanation
Explanation 1:
A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10
Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and
splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.
Explanation 2:

A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
1st day: 3, 2
2nd day: 2, 4
3rd day: 1, 4

*/

bool canShip(vector<int> A, int cap, int d)
{
    int sum = 0;
    int count = 1;
    for (int i = 0; i < A.size(); i++)
    {
        sum += A[i];
        if (sum > cap)
        {
            sum = A[i];
            if (sum > cap)
            {
                return false;
            }
            count++;
        }
    }
    if (count <= d)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int solve(vector<int> &A, int B)
{
    // sort(A.begin(),A.end());
    int high = 0;
    int low = INT_MAX;
    for (int i = 0; i < A.size(); i++)
    {
        high += A[i];
        low = min(low, A[i]);
    }

    int ans = INT_MAX;
    //    cout<<low<<" "<<high<<endl;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        bool temp = canShip(A, mid, B);
        // cout<<mid<<" "<<temp<<endl;
        if (temp)
        {

            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
