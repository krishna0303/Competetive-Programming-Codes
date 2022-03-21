
//idea is to find out all non prime numbers till 1000 and then check from low to high if that smallest non prime
//number is exist in the main given string as a subsequences i.e we can get that number by deleting atmost charcaters tghe
//that number we have to print

/*
here is the link of problem:
https://codeforces.com/problemset/problem/1562/B

*/

#include <bits/stdc++.h>
using namespace std;

bool isPrime[1001];
vector<int> prime;

void precompute()
{
    for (int i = 0; i < 1001; i++)
    {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i * i <= 1000; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= 1000; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 1; i <= 1000; i++)
    {
        if (isPrime[i] == false)
        {
            prime.push_back(i);
        }
    }
}

bool isSubsequence(string s1, string s2)
{
    int i = 0, j = 0;
    int n = s1.length();
    int m = s2.length();
    while (i < n && j < m)
    {
        if (s1[i] == s2[j])
        {
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }
    if (j == m)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    precompute();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        for (int i = 0; i < prime.size(); i++)
        {
            string str = to_string(prime[i]);
            if (isSubsequence(s, str))
            {
                cout << str.length() << endl;
                cout << stoi(str) << endl;
                break;
            }
        }
    }
}