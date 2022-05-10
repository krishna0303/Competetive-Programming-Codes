

#include <bits/stdc++.h>
using namespace std;

/*
Problem Description



Given a column title A as appears in an Excel sheet, return its corresponding column number.



Problem Constraints
1 <= |A| <= 100



Input Format
First and only argument is string A.



Output Format
Return an integer



Example Input
Input 1:

 "A"
Input 2:

 "AB"


Example Output
Output 1:

 1
Output 2:

 28


*/

// this problem is same as burn tree with little variation

int titleToNumber(string A)
{
    int ans = 0;
    int temp = 1;
    for (int i = A.length() - 1; i >= 0; i--)
    {
        int val = A[i] - 'A';
        val += 1;
        ans += (val * temp);
        temp = temp * 26;
    }
    return ans;
}
