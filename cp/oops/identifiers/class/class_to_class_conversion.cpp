#include <bits/stdc++.h>
using namespace std;

class Item;

class Product
{
private:
    int m, n;

public:
    void setData(int x, int y)
    {
        m = x;
        n = y;
    }
    int getM()
    {
        return m;
    }
    int getN()
    {
        return n;
    }
    // operator Item()
    // {
    //     Item i;
    //     // i.a = m;
    //     // i.b = n;
    //     return i;
    // }
};

class Item
{
private:
    int a, b;

public:
    Item()
    {
    }
    void showData()
    {
        cout << a << " " << b << endl;
    }
    Item(Product p) //it is done by copy constrcutor
    {
        a = p.getM();
        b = p.getN();
    }
};

int main()
{
    Item i1;
    Product p;
    p.setData(3, 4);
    i1 = p;
    i1.showData();
    return 0;
}