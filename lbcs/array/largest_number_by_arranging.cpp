
#include <bits/stdc++.h>
using namespace std;

/*
Given a list of non negative integers, arrange them such that they form the largest number.

For example:

Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.


*/
// when given is not const type
bool compare(int a, int b)
{
    string s1 = to_string(a), s2 = to_string(b);
    return s1 + s2 > s1 + s2;
}

string largestNumber(const vector<int> &A)
{
    sort(A.begin(), A.end(), compare);
    string ans = "";
    for (int i = 0; i < A.size(); i++)
    {
        ans += A[i];
    }

    return ans;
}

// when given vector is const type

static bool compareNum(string a, string b)
{
    return a + b > b + a;
}

string largestNumber(const vector<int> &num)
{
    string result;
    vector<string> str;
    for (int i = 0; i < num.size(); i++)
    {
        str.push_back(to_string(num[i]));
    }
    sort(str.begin(), str.end(), compareNum);
    for (int i = 0; i < str.size(); i++)
    {
        result += str[i];
    }

    int pos = 0;
    while (result[pos] == '0' && pos + 1 < result.size())
        pos++;
    return result.substr(pos);
}
