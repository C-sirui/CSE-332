#include <iostream>
#include "tools.h"

using namespace std;

int main()
{

// Q2

    //int a = 1;
    //int b = 2;

    //int& a_ = a;
    //int& b_ = b;

    //int&& r_a = a*2;
    //int&& r_b = b+b;

    //cout << r_a << ", " << r_b << endl


// Q3

    //int a = 1;
    //int b = 2;
    //
    //int&& r_a = move(a);
    //int&& r_b = move(b);

    //cout << r_a << ", " << r_b << endl;

    //int c = r_a;
    //int d = r_b;

    //cout << c << ", " << d << endl;


// Q4
    //Wrapper a;
    //Wrapper b(a);
    //Wrapper c;
    //c = a;

// Q5
    //Wrapper a;
    //Wrapper b = move(a); // wrapper a is destroyed
    //Wrapper c;
    //Wrapper d(c);

// Q6
    Wrapper a;
    Wrapper temporary;
    a = temporary;
    Wrapper b = move(a);

    return 0;
}

