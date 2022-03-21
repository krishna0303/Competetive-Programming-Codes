#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <queue>
#include <sstream>
#include <typeinfo>
#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.first < b.first;
}
int securitiesBuying(int z, int security_value[], int n)
{
    int no_of_stocks = 0;
    // int n = sizeof(security_value) / sizeof(security_value[0]);
    // cout << n + 1 << endl;
    vector<pair<int, int>> p;
    for (int i = 0; i < n; i++)
    {
        p.push_back({security_value[i], i + 1});
    }
    sort(p.begin(), p.end(), compare);
    // cout << p.size() << endl;
    for (int i = 0; i < p.size(); i++)
    {
        // cout << p[i].first << " " << p[i].second << endl;
        // cout << z << endl;
        if ((p[i].second * p[i].first) > z)
        {
            // cout << "ch" << endl;
            int t = z / p[i].first;
            no_of_stocks += t;
            z -= t * p[i].first;
            break;
        }
        else
        {
            no_of_stocks += p[i].second;
            z -= (p[i].first * p[i].second);
        }
    }

    return no_of_stocks;
}

int main()
{

    int z;
    cin >> z;
    vector<int> input_data;
    string buffer;
    int data;
    getline(cin, buffer);
    getline(cin, buffer);
    istringstream iss(buffer);

    while (iss >> data)
        input_data.push_back(data);

    int n = input_data.size();

    int security_value[n];
    for (int i = 0; i < n; i++)
    {
        security_value[i] = input_data[i];
    }

    int no_of_stocks_purchased = securitiesBuying(z, security_value, n);
    cout << no_of_stocks_purchased;
}
