#include <bits/stdc++.h>
using namespace std;

class Account
{
private:
    int balance;
    static float roi;

public:
    void display()
    {
        cout << balance << endl;
    }
};

float Account::roi = 3.5f;

int main()
{
    Account a1;
    cout<<Account::roi<<endl;;
}
