/*

Given an array of strings arr[], the task is to sort the array of strings according to the frequency of each string, in ascending order.
If two elements have the same frequency, then they are sorted into lexicographical order.
Input: arr[] = {“Geeks”, “for”, “Geeks”}
Output: {“for”, “Geeks”}
Explanation:
As the string “Geeks” has a frequency of 2 in the given array,
Hence, the position of the string “Geeks” will be 2

Input: arr[] = {“abc”, “pqr”, “pqr”, “abc”}
Output: {“abc”, “pqr”}
Explanation:
As both the strings have the same frequency, the array is sorted in the lexicographical order.

*/

// C++ implementation to sort the
// array of strings by its frequency

#include <bits/stdc++.h>
using namespace std;

// Custom comparator function to
// sort the string by its frequency
bool cmp(pair<int, string> x,
         pair<int, string> y)
{

    // Condition to check if the
    // frequency of the string is less
    if (x.first < y.first)
    {
        return true;
    }

    // Condition to check if the
    // frequency of the string is greater
    else if (x.first > y.first)
    {
        return false;
    }

    // Condition when frequency of
    // the strings is equal
    else
    {

        // Condition to check if the
        // first string is lexicographically
        // smaller than second string
        if (x.second < y.second)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

// Function to sort the array of strings
// by its frequency in the array
void printArraystring(string str[], int n)
{
    unordered_map<string, int> m;

    // Loop to store the frequency
    // of a string in a hash-map
    for (int i = 0; i < n; i++)
    {
        m[str[i]]++;
    }

    // Iterator for the map
    vector<pair<int, string>> vec;

    // Loop to store the frequency and
    // string in a vector
    for (auto it = m.begin(); it != m.end();
         it++)
    {
        vec.push_back(
            make_pair(it->second, it->first));
    }

    // Sort the string
    // using custom comparator
    sort(vec.begin(), vec.end(), cmp);

    // Loop to print the sorted vector
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i].second << ", ";
    }
}

// Driver Code
int main()
{
    string arr[] = {"Geeks", "for", "Geeks",
                    "for", "arc"};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Function to perform sorting
    printArraystring(arr, n);

    return 0;
}
