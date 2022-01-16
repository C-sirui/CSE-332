#include <iostream>
#include "studio12code.h"
using namespace std;



Shape::Shape(int area)
{
    area_ = area;
    cout << "Shape" << endl;
}

Shape::~Shape() {
    cout << "~Shape" << endl;
}

triangle::triangle(int area):
{
    area_ = area;
    cout << "triangle" << endl;
}

triangle::~triangle()
{
    cout << "~triangle" << endl;
}

int main()
{
    std::cout << "Hello World!\n";
    Shape a(1);
    triangle b(2);
}


