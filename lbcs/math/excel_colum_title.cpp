

#include <bits/stdc++.h>
using namespace std;

/*
Problem Description

Given a positive integer A, return its corresponding column title as appear in an Excel sheet.



Problem Constraints
1 <= A <= 1000000000



Input Format
First and only argument is integer A.



Output Format
Return a string, the answer to the problem.



Example Input
Input 1:

 A = 1
Input 2:

 A = 28


Example Output
Output 1:

 "A"
Output 2:

 "AB"

*/

string convertToTitle(int n)
{
    string ans = "";
    while (n != 0)
    {
        int rem = n % 26;
        // cout<<rem<<" "<<n<<endl;
        if (rem == 0)
        {
            rem = 26;
        }

        char c = 'A' + rem - 1;
        ans = c + ans;
        n /= 26;
    }
    return ans;
}
