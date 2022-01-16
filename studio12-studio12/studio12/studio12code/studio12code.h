#pragma once

#ifndef STUDIO12CODE_H
#define STUDIO12CODE_H
#include <iostream>
using namespace std;

class Shape
{
public:
	Shape();
	Shape(int area);
	~Shape();

private:
	int area_;
};

class triangle :public Shape {
public:
	triangle(int area);
	~triangle();
private:
	int area_;
};


#endif

