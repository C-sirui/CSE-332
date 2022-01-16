#pragma once

#ifndef STUDIO13CODE_H
#define STUDIO13CODE_H

#include <iostream>
using namespace std;

class detect {
private:
	unsigned int cnt_;
	static unsigned int wut;
public:
	detect() {
		cnt_ = wut;
		wut++;
		cout << "detect" << ": " << this << ", count: " << cnt_ << endl;
	};
	~detect() {
		cout << "~detect" << ": " << this << ", count: " << cnt_ << endl;
	}
};
unsigned int detect::wut = 0;

#endif