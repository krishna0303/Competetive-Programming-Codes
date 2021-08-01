#include <bits/stdc++.h>
using namespace std;

//major difference in class is members are public by defualt in structure and private in class

struct Complex
{
private:
    int a, b;

public:
    void set_data(int x, int y)
    {
        a = x, b = y;
    }
    void get_data()
    {
        cout << "\na is " << a << " and b is " << b << endl;
    }
};
class Complex1
{
    // private: //if we don't write it in private it is by default private in class
    //only here we have to take care of members which we want to make public
    int a, b;

public:
    void set_data(int x, int y)
    {
        a = x, b = y;
    }
    void get_data()
    {
        cout << "\na is " << a << " and b is " << b << endl;
    }
};
int main()
{
    Complex1 c1;
    c1.set_data(4, 5);
    c1.get_data();
    // cout << c1.a << endl;

    return 0;
}