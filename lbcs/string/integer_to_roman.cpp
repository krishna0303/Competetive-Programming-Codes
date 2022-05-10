

#include <bits/stdc++.h>
using namespace std;

/*

Another question which belongs to the category of questions which are intentionally stated vaguely.

Expectation is that you will ask for correct clarification or you will state your assumptions before you start coding.

Given an integer A, convert it to a roman numeral, and return a string corresponding to its roman numeral version

Note : This question has a lot of scope of clarification from the interviewer. Please take a moment to think of all the needed clarifications and see the expected response using “See Expected Output”

For the purpose of this question, https://projecteuler.net/about=roman_numerals has very detailed explanations.




Input Format

The only argument given is integer A.
Output Format

Return a string denoting roman numeral version of A.
Constraints

1 <= A <= 3999
For Example

Input 1:
    A = 5
Output 1:
    "V"

Input 2:
    A = 14
Output 2:
    "XIV

*/

// string arr[9]={"I","II","III","IV","V","VI","VII","VIII","IX"};
// unordered_map<int,string>m;
// m[10]="X";
// m[50]="L";
// m[100]="C";
// m[500]="D";
// m[1000]="M";

string intToRoman(int A)
{
    int intCode[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string code[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    string str = "";
    for (int i = 0; i < 13; i++)
    {
        while (A >= intCode[i])
        {
            str += code[i];
            A -= intCode[i];
        }
    }
    return str;
    // if(A>=1000){
    //     int val=A/1000;
    //      A=A-(val*1000);
    //     string str="";
    //     while(val!=0){
    //         str+="M";
    //         val--;
    //     }

    //     return str+intToRoman(A);
    // }
    // if(A>=500){
    //     int val=A/500;
    //      A=A-(val*500);
    //     string str="";
    //     while(val!=0){
    //         str+="D";
    //         val--;
    //     }

    //     return str+intToRoman(A);

    // }
    // if(A>=100){
    //     int val=A/100;
    //      A=A-(val*100);
    //     string str="";
    //     while(val!=0){
    //         str+="C";
    //         val--;
    //     }

    //     return str+intToRoman(A);
    // }
    // if(A>=50){
    //     int val=A/50;
    //     A=A-(val*50);
    //     string str="";
    //     while(val!=0){
    //         str+="L";
    //         val--;
    //     }

    //     return str+intToRoman(A);
    // }
    // if(A>=10){
    //     int val=A/10;
    //      A=A-(val*10);

    //     string str="";
    //     while(val!=0){
    //         str+="X";
    //         val--;
    //     }

    //     // cout<<A<<endl;
    //     return str+intToRoman(A);

    // }
    // if(A>=1){
    //     return arr[A-1];
    // }
    // if(A<=0){

    //     return "";
    // }
}
