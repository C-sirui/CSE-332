#include<iostream>
#include "tools.h"
using namespace std;

unsigned int Detector::COUNT = 0;

Detector::Detector() 
{
	this->id = COUNT;
	++Detector::COUNT;
	cout << "    " << "Detector: " << this << " has " << "id " << this->id  << endl;
}

Detector::~Detector() 
{
	cout << "    " << "~Detector: " << this << " has " << "id " << this->id << endl;
}

Wrapper::Wrapper()
{
	this->detector_p = 0;
	this->detector_p = new Detector;
	b_ = true;
}

Wrapper::Wrapper(const Wrapper& w)
{
	cout << "----------Copy constructor start----------" << endl;
	cout << "Global count at start: " << w.detector_p->COUNT << endl;
	cout << "Original wrapper id at start: " << w.detector_p->id << endl;

	this->detector_p = w.detector_p;
	this->b_ = false;

	cout << "----------Copy constructor end----------" << endl;
	cout << "Global count at end: " << w.detector_p->COUNT << endl;
	cout << "Original wrapper id at end: " << w.detector_p->id << endl;
	cout << "Copy wrapper id at end: " << this->detector_p->id << endl;
	cout << endl;
}

Wrapper::~Wrapper()
{
	if (b_)
	{
		delete detector_p;
	}
}

Wrapper& Wrapper::operator=(const Wrapper& w)
{
	cout << "----------Copy-assignment constructor start----------" << endl;
	cout << "Global count at start: " << w.detector_p->COUNT << endl;
	cout << "Original wrapper id at start: " << w.detector_p->id << endl;
	
	if (this != &w) {

		Wrapper n(w);
		std::swap(n.detector_p, this->detector_p);
		std::swap(n.b_, this->b_);
	}

	cout << "----------Copy-assignment constructor end----------" << endl;
	cout << "Global count at end: " << w.detector_p->COUNT << endl;
	cout << "Original wrapper id at end: " << w.detector_p->id << endl;
	cout << "Copy wrapper id at end: " << this->detector_p->id << endl;
	cout << endl;
	return *this;
}

Wrapper::Wrapper(Wrapper&& w): detector_p(w.detector_p), b_(w.b_)
{
	cout << "----------Move constructor start----------" << endl;
	cout << "Global count at start: " << w.detector_p->COUNT << endl;
	cout << "Original wrapper id at start: " << w.detector_p->id << endl;

	w.detector_p = nullptr;
	w.b_ = true;

	cout << "----------Move constructor end----------" << endl;
	cout << "Global count at start: " << w.detector_p->COUNT << endl;
	cout << "Original Copy points to null, Copy wrapper id at end: " << this->detector_p->id << endl;
	cout << endl;
}

Wrapper& Wrapper::operator=(Wrapper&& w)
{
	if (&w != this) 
	{
		cout << "----------Move-assignment constructor start----------" << endl;
		cout << "Global count at start: " << w.detector_p->COUNT << endl;
		cout << "Original wrapper id at start: " << w.detector_p->id << endl;

		// free copy wrapper members
		delete this->detector_p;
		b_ = true;
		// move original wrapper members to copy
		this->detector_p = w.detector_p;
		this->b_ = w.b_;
		// set w to null
		w.detector_p = nullptr;
		w.b_ = true;

		cout << "----------Move-assignment constructor end----------" << endl;
		cout << "Global count at start: " << w.detector_p->COUNT << endl;
		cout << "Original Copy points to null, Copy wrapper id at end: " << this->detector_p->id << endl;
		cout << endl;

	}
	return *this;
}

	

