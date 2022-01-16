#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <forward_list>
#include <deque>
using namespace std;

int main()
{
    vector<int> vec = { 1,2,3 };
    forward_list<int> fl = { 1,2,3,4 };
    list<int> l = { 1,2,3,4,5 };
    deque<int> dk = { 1,2,3,4,5,6 };

    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(6);
    for (auto vp = vec.cbegin(); vp != vec.end(); ++vp) {
        cout << *vp;
    }
    cout << endl;
    fl.push_front(6);
    fl.remove(1);
    fl.push_front(5);
    fl.remove(2);
    fl.push_front(4);
    fl.remove(3);
    fl.push_front(3);
    fl.push_front(2);
    fl.push_front(1);
    fl.remove(4);
    for (auto flp = fl.cbegin(); flp != fl.end(); ++flp) {
        cout << *flp;
    }

    std::cout << "Hello World!\n";
}

