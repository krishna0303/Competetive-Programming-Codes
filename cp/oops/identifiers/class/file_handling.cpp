#include <bits/stdc++.h>
using namespace std;
int main()
{
    // ofstream fout;
    // fout.open("abc.text", ios::app);
    // int pos = fout.tellp(); tellp function batat hai ki abhi kis position lo point kar raha hai put pointer
    // cout << pos << endl;
    // fout << "krishna";
    // pos = fout.tellp(); tellp provide last byte where data should be start entering into abc.text file
    // cout << pos << endl;
    // fout.close();

    // ifstream fin;
    // fin.open("abc.text", ios::in);
    // int pos = fin.tellg();
    // cout << pos << endl;
    // char ch;
    // fin >> ch; this is not able to read space
    // cout << ch << endl;
    // pos = fin.tellg();
    // cout << pos << endl;
    //ch=fin.get();this will also read space as well
    // while (!(fin.eof()))
    // {
    //     fin >> ch; agar is type se input read karte hai file se to wo space backslash '\n' and tab space ko read nahi karta to ske liye fin.get() function ka use kar sakte hain
    //jo ki hame us character ka integer value return karta hai and hum use tupe kcast kar sakte hain chyarcater mein (char)72 like this or we can store into char variablew
    //     cout << ch << endl;
    //     pos = fin.tellg(); teelg bata hai ki abhi kis character or data ko pint kar raha hai get pointer
    //     cout << pos << endl;
    // }
    // fin.close();

    //seekg and seekp

    // ifstream fin;
    // fin.open("abc.text");
    // cout << fin.tellg() << endl;
    // cout << (char)fin.get() << endl;
    // cout << fin.tellg() << endl;
    // cout << (char)fin.get() << endl; //fin.get function ek input read karne ke bad next input pe automatically shift ho jata hai
    // cout << fin.tellg() << endl;

    // fin.seekg(7);
    // cout << fin.tellg() << endl;
    // cout << (char)fin.get() << endl; //fin.get function ek input read karne ke bad next input pe automatically shift ho jata hai
    // cout << fin.tellg() << endl;

    // // fin.seekg(100);
    // // cout << (char)fin.get() << endl;
    // // cout << fin.tellg() << endl;
    // fin.seekg(2);
    // cout << (char)fin.get() << endl;
    // cout << fin.tellg() << endl;
    // // fin.seekg(2, ios_base::cur); //pointer ka position 2 se age bad jaye
    // // cout << (char)fin.get() << endl;
    // // cout << fin.tellg() << endl;
    // fin.seekg(2, ios_base::beg); //pointer ka position 2 se age bad jaye
    // cout << (char)fin.get() << endl;
    // cout << fin.tellg() << endl;

    // fin.seekg(-2, ios_base::end); //pointer ka position 2 se age bad jaye
    // cout << (char)fin.get() << endl;
    // cout << fin.tellg() << endl;

    //seekp

    ofstream fout;
    fout.open("abc.text", ios::ate | ios::app);
    cout << fout.tellp() << endl;

    fout.seekp(4, ios_base::beg);
    cout << fout.tellp() << endl;
    fout << "chnaged";
    // cout << fout.tellp() << endl;
    fout.close();

    return 0;
}