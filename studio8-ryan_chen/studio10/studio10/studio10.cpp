// studio10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <iterator>
#include <array>
using namespace std;


int main(int argc, char* argv[])
{
    set<string> set;
    multiset<string> mset;
    map<string, int> map;
    auto it = mset.begin();
    if (argc == 0) {
        return -1;
    }
    copy(argv+1, argv+argc, inserter(mset, it));

    for (multiset<string>::iterator it = mset.begin(); it != mset.end(); ++it) {
        std::cout << ' ' << *it;
        std::cout << '\n';
    }
       

    return 0;

    cout << "Hello World!\n";


}

