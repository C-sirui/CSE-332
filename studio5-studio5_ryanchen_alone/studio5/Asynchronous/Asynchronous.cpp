
#include <iostream>
using namespace std;

void mySwap(int& a, int& b) {
    int c = 0;
    c = a;
    a = b;
    b = c;
    cout << "mySwap Version1--Done Swapping" << endl;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "&a: " << &a << endl;
    cout << "&b: " << &b << endl;
}

void mySwap(int*& a, int*& b) {
    // parameters are pointer of address of pointers
    int* c = a;
    a = b;
    b = c;
    cout << "mySwap Version2--Done Swapping" << endl;
    cout << "a: " << *a << endl;
    cout << "b: " << *b << endl;
    cout << "&a: " << a << endl;
    cout << "&b: " << b << endl;
}

void mySwap(int* const& a, int* const& b) {
    // reference to a constant pointer of a and b
    // can only change the integer value
    int c = *a;
    *a = *b;
    *b = c;
    cout << "mySwap Version3--Done Swapping" << endl;
    cout << "a: " << *a << endl;
    cout << "b: " << *b << endl;
    cout << "&a: " << a << endl;
    cout << "&b: " << b << endl;
}

int main()
{
    int a = 1;
    int b = 2;
    int* a_ = &a;
    int* b_ = &b;
    int* const& a__ = a_;
    int* const& b__ = b_;

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "&a: " << a_ << endl;
    cout << "&b: " << b_ << endl;

    mySwap(a__, b__);

}


