

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
/*
Problem Description



You are given an array of logs. Each log is a space-delimited string of words, where the first word is the identifier.

There are two types of logs:

Letter-logs: All words (except the identifier) consist of lowercase English letters.
Digit-logs: All words (except the identifier) consist of digits.

Reorder these logs so that:

The letter-logs come before all digit-logs.
The letter-logs are sorted lexicographically by their contents. If their contents are the same, then sort them lexicographically by their identifiers.
The digit-logs maintain their relative ordering.

Return the final order of the logs.

*/

bool compare(string s1, string s2)
{
    string aa = s1.substr(s1.find('-'));
    string bb = s2.substr(s2.find('-'));

    return aa == bb ? s1 < s2 : aa < bb;
}
vector<string> reorderLogs(vector<string> &A)
{
    vector<string> result;
    int count = 0;
    for (auto log : A)
    {
        if (log.back() <= 'z' and log.back() >= 'a')
        {
            result.insert(result.begin(), log);
            count++;
        }
        else
            result.push_back(log);
    }
    sort(result.begin(), result.begin() + count, compare);
    return result;
}
