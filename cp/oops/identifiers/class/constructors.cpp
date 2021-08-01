#include <bits/stdc++.h>
using namespace std;
//there is two type of constrcutors:
//if no counstrcutor is created by the programmer then compiler automatically create default and copy constructor

//default constrcutor:
//if any constrcutor define in class then default constructor will not be called automatically via compiler but copy constructor will be created by compiler and there is no
//any kind of constrcutor created then only default constrcutor created by compiler

//copy constrcutor

//if copy constrcutor is crerated in class then compiler will jot creat any construcotr automatically
//to make a copy constrcutor pass same class object as formal arguement as reference otherwise if
//we pass it as normal same class object then will go into infinite recursion

class Complex
{
private:
    int a;
    int b;

public:
    Complex(int x, int y)
    {
        a = x;
        b = y;
    }
    Complex(int x)
    {
        a = x;
        b = x;
    }
    Complex()
    {
    }

    //copy constructor
    // Complex(Complex c){ this will cause infinite recursion beacuse here we are initializing c=c1  => which is similar to c(c1) and agin same thing hapen again anad again
    //     a=c.a;
    //     b=c.b;
    // }
    Complex(Complex &c)
    { //to avoid infinite loop we have to take formal argument in funcgtion as refernce
        a = c.a;
        b = c.b;
    }
    ~Complex(){

    }
};

int main()
{
    Complex c1(3, 4), c2 = Complex(5, 6), c3 = 5; //(this is only for single arguemnt),
    Complex c4(c1);                               //it will call copy constrcutor in this situation
}
