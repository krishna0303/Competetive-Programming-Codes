#include <bits/stdc++.h>
using namespace std;

namespace MySpace
{
    int n;
    class Car
    {
    private:
        int a, b;

    public:
        void setData(int, int);
        void showData();
    };
    void fun(string name);
}

// using namespace MySpace; it we use this line then we don't need to use MySpace:: scope resoultion or membership level before their meber varibales or functions

void MySpace::Car::setData(int x, int y)
{
    a = x;
    b = y;
}
void MySpace::Car::showData()
{
    cout << a << " " << b << endl;
}

void MySpace::fun(string name)
{
    cout << "your name is :" << name << endl;
}

int main()
{
    namespace ms = MySpace;
    ms::Car obj;

    obj.setData(3, 4);
    obj.showData();
    cout << ms::n << endl;
    ms::fun("krishna");

    return 0;
}