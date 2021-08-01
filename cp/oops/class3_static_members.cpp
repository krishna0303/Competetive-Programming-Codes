#include <bits/stdc++.h>
using namespace std;

//major difference in class is members are public by defualt in structure and private in class

class Account
{
private:         //it is good practice to write private and public other wise if we don't write private in class then it is also fine becauyse in class memebers are by default orivate
    int balance; //instance member variable

    static float roi; //static member vaiavle or class variable

public:
    void set_balance(int b) //instance member function
    {
        balance = b;
        // cout << roi << endl; it is fine
    }

    static void set_roi(float r) //class function or static member function
    {
        roi = r;
        // cout << balance << endl; it is not fine it only acces static member variable
    }
};

float Account::roi = 4.8;
int main()
{
    Account a1, a2;
    a1.set_roi(4.5);
    Account::set_roi(3.2);

    return 0;
}