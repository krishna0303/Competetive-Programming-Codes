#include <bits/stdc++.h>
using namespace std;

//major difference in class is members are public by defualt in structure and private in class

class Complex
{
private: //it is good practice to write private and public other wise if we don't write private in class then it is also fine becauyse in class memebers are by default orivate
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

    Complex add(Complex c)
    {
        Complex temp;
        temp.a = a + c.a;
        temp.b = b + c.b;
        return temp;
    }
};
int main()
{
    Complex c1, c2, c3;
    c1.set_data(4, 5);
    c2.set_data(6, 5);
    c3 = c1.add(c2);
    c3.get_data();
    // cout << c1.a << endl;

    return 0;
}