#include <bits/stdc++.h>
using namespace std;

class Dummy
{
private:
    int a, b;
    const int x; //const means yeah ek constant variable ban gya hai iska value change nahi ho sakta hai throught the program and isko declaration ke time pe hi intialize karna hota hai
    int &y;      //refernce varible ko bhi initialize karna padta hai during declaration
    Dummy(int &n) : x(5), y(n)
    {
        //we can intialize const variable and reference variable inside the constrcutor so we have to used initializers list ot initialize
    }
}

int
main()
{
    int m = 8;
    Dummy obj(m);
    obj return 0;
}
