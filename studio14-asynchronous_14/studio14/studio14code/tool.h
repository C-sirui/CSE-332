#pragma once


#include <iostream>
using namespace std;

class detector {
private:
	static unsigned int ref_;
	unsigned int counter_;
public:
	detector(const detector* c):counter_(c->counter_) {
	}
	detector() {
		counter_ = ref_;
		ref_++;
		cout << "detector: " << this << "counter: " << counter_ << endl;
	};
	~detector() {
		cout << "~detector: " << this << "counter: " << counter_ << endl;
	};
	unsigned int get_counter() {
		return counter_;
	}

};
unsigned int detector::ref_ = 0;

class wrapper {
private:
	detector* wrap_d;
	bool boo;
public:
	//// shallow copy
	//wrapper(const wrapper* c) :boo(false), wrap_d(c->wrap_d) {
	//	cout << "shallowly copied, a new wrapper constructed" << endl;
	//}
	// deep copy
	wrapper(const wrapper* c) : boo(true), wrap_d(0) {
		detector deep(*c->wrap_d);
		wrap_d = &deep;
		cout << "shallowly copied, a new wrapper and detector constructed" << endl;
		
	}
	wrapper() {

		wrap_d = 0;
		detector* a = new detector();
		wrap_d = a;
		cout << "wrapper constructed" << endl;
	}
	~wrapper() {
		if (boo) {
			delete wrap_d;
		}
		cout << "~wrapper" << endl;
	}

};



