
#include <iostream>
#include<list>
#include<forward_list>
#include<iterator>
#include<vector>
#include<set>
#include"MyVect.h"
#include "MyVectWithStats .h"
using namespace std;

//Q1

//// Q1
//void foo1(int i, int* const j, const int& k) {
//    *j = i;
//    i += k;
//    i = *j + k;
//}
//int& foo2(int i) {
//    int x = 10 * i;
//    return x;
//}
//void foo3(const char*& s) {
//    char first = *s;
//    cout << first << endl;
//    ++s;
//}
//void fuck(char* j ) {
//	*j = 'z';
//	j++;
//}
//int main(int argc, char* argv[]) {
//	char i[] = {'h','e'};
//	cout << *i << endl;
//	fuck(i);
//	cout << *i << endl;
//	cout << i[1] << endl;
//
//
//	//int a = 2;
//    //int b = 5;
//    //int c = 7;
//    //foo1(a, &b, c);
//    //cout << a << " " << b << " " << c << endl; // 1: "2 2 7"
//    //int& p = foo2(5);
//    //cout << p << endl; // foo2 returns a destroyed local variable, but in this case it doesn't cause problem: 50
//    //const char* d = "hello";
//    //foo3(d); // 3: "h"
//    //cout << *d << endl; // 4: "e"
//    //return 0;
//}

//Q2


//int main() {
//	forward_list<int> li;
//	li.push_front(2);
//	li.push_front(3);
//	li.push_front(4);
//	//cout << li[2] << endl; operator [] is not defined for forward_list
//}
//
//void func(vector<int>::iterator it) {
//	it += 2;
//	return;
//}
//int main(int argc, char* argv[]) {
//	vector<int> v = { 0, 1, 2, 3, 4 };
//	auto it = v.begin();
//	func(it);
//	cout << *it << endl; // pass by value, so it prints 0
//	return 0;
//}
//
//int* func() {
//	int j = 10;
//	int* p = new int(j);
//	return p;
//}
//int main(int argc, char* argv[]) {
//	int* p = func();
//	cout << *p << endl;
//	delete p; // u need to delete this because what p points to wasn't declared in main and main won't delete it when function ends.
//	return 0;
//}
//
//int main() {
//	int arr[5] = { 1,2,3,4,5 };
//	int i;
//	int* p = arr + i; // i is uninitialized, so this behavior is not defined. U can call it "Indexing out of the bounds of a container, behavior is undefined"
//	cout << *p << endl;
//}
//
//int main() {
//	int i = 1;
//	const int j = 50;
//	int* p = &i;
//	*p = 50;
//	p = &j; // can not use int pointer for const int variable
//	cout << *p << endl;
//}
//
//int main() {
//	int i = 5;
//	int j = 20;
//	int& k = j;
//	int* m = &i;
//	k = *m;
//	cout << "i: " << i << " j : " << j << endl;
//}
////
//int main(int argc, char* argv[]) {
//	int* p = new int(10);
//	int& r = *p;
//	delete p;
//	p = nullptr;
//	cout << r << endl; // uninitialized reference since what r alias to is now deleted
//}
////
//int main() {
//	const char* c = "cse332";
//	const char* e = " exam";
//	char* concat = c + e; //illegal pointer arithmatic
//	cout << concat << endl;
//}
//
//int main() {
//	int arr[] = { 1,2,3,4,5 };
//	int* p = &arr[3];
//	cout << *p << endl;
//	int* q = arr + 1;
//	cout << *q << endl;
//	int distance = p - q;
//	int difference = *p - *q;
//	cout << "dist: " << distance << " diff: " << difference << endl; // prints 2 and 2
//}
//
//int main() {
//	int i = 2;
//	int j = 3;
//	int k = 4;
//	vector<int> v;
//	v.push_back(i);
//	v.push_back(j);
//	v.push_back(k);
//	v[0] = 15;
//	v[1] = 16;
//	v[2] = 17;
//	cout << "i: " << i << " j: "  << j
//		<< " k: "  << k;
//}
//
//short bar(short i) {
//	return i;
//}
//long bar(long i) {
//	return i;
//}
//int main(int argc, char* argv[]) {
//	char c = 'c';
//	cout << bar(c) << endl; // ambiguous function call
//}
//
//int mian() {
//	int arr[5] = { 1,2,3,4,5 };
//	int* const p = arr + 2;
//	cout << *p << endl;
//	++p;  // can't modify a const variable
//	cout << *p << endl;
//}


//Q3

//int main(int argc, char* argv[]) {
//	MyVect v(10); // 1
//	v.push(5).push(10).push(15); // 2
//	cout << "v: " << v << endl; // 3
//	MyVect v2 = v; // 4
//	v2[0] = 20;
//	cout << "v2: " << v2 << endl; // 5
//	cout << "v: " << v << endl; // 6
//	v = v; // 7
//	cout << "v: " << v << endl; // 8
//	cout << "emnd" << endl;
//	return 0;
//}s
//MyVect Constructor Version 1
//v: 5 10 15
//since each push function returns the necessary parameter of push function
//MyVect assignment Version 1
//v2 : 20 10 15
//v1 : 5 10 15
//MyVect assignment Version 1
//v :
//	MyVector destructor
//	MyVector destructor
//
//	double deletion, in v = v, you have already deleted arr, when function return, you deleted it again, so it crush
//
//int main(int argc, char* argv[]) {
//	// ContainerStats s(100,0,0); // 1
//	MyVectWithStats mvs(10, 100, 0, 0); // 2
//	mvs.print_range();
//	ContainerStats* p = &mvs;
//	p->print_range(); // 4
//	p->print(); // 5
//	return 0;
//}

//int main(int argc, char* argv[])
//{
//	set<MyVectWithStats> s;
//	MyVectWithStats V1(10, 100, 0, 0);
//	V1.insert_and_update(10);
//	V1.insert_and_update(10);
//	MyVectWithStats V2(10, 100, 0, 0);
//	V2.insert_and_update(50);
//	V2.insert_and_update(10);
//	MyVectWithStats V3(10, 100, 0, 0);
//	V3.insert_and_update(4);
//	V3.insert_and_update(15);
//	s.insert(V1);
//	s.insert(V2);
//	s.insert(V3);
//	for (auto start = s.begin(); start != s.end(); ++start) { // 1
//		start->print(); // 2
//	} // 3
//	return 0;
//}

int main() {
	int i = 10;
	int* ip = &i;
	ip = nullptr;
	delete& i;
	return 0;
}