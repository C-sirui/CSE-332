// studio14code.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Ryan Chen
// studio14
// 
//

#include <iostream>
using namespace std;
#include "tool.h"

int main()
{
    std::cout << "Hello World!\n";
    wrapper a;
    wrapper b(&a);
    return 0;
}
