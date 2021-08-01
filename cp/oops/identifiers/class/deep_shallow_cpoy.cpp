#include <bits/stdc++.h>
using namespace std;

class Dummy
{
private:
    int a;
    int b;
    int *p;

    Dummy()
    {
        p = new int; //ek meory ban jayega int type ka aur uska addres p me store ho jayega
    }

    void setData(int x, int y, int z)
    {
        a = x;
        b = y;
        *p = z; //*p us memory block ke value ko point karne lagega jiska usne address conmtain kiya tha
    }
    void showData()
    {
        cout << x << " " << y << " " << *p << endl;
    }

    Dummy(Dummy &d)
    {
        a = d.a;
        b = d.b;
        p = new int;
        *p = *(d.p);
    }
    ~Dummy()
    {
        delete p;
    }
};
int main()
{
    Dummy d1;
    d1.setData(3, 4);
    Dummy d2 = d1; //copy constrcutor jab bhi hum same class ke object ko pass karte hai for intialixation it then there is copy constructor call hota hai
    Dummy d2;
    d2 = d1; //implicit copy asignement operatror
}