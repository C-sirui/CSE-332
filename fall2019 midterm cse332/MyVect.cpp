#include "MyVect.h"

using namespace std;
enum vect_exceptions { index_out_of_bounds = 1, out_of_space };

MyVect::MyVect(unsigned int s) : arr(nullptr), size(0), max_size(s) {
	std::cout << "MyVect Constructor Version 1" << std::endl;
	arr = new int[max_size];

};

MyVect::MyVect(const MyVect& a) : arr(nullptr), size(0), max_size(0) {
	std::cout << "MyVect Constructor Version 2" << std::endl;
	if (a.max_size > 0) {
		arr = new int[a.max_size];
		max_size = a.max_size;
		size = a.size;
		for (unsigned int i = 0; i < size; ++i) {
			arr[i] = a.arr[i];

		}

	}

}

MyVect::~MyVect() {
	std::cout << "MyVect destructor" << std::endl;
	delete[] arr;

}

MyVect& MyVect::operator=(const MyVect& a) {
	std::cout << "MyVect assignment Version 1" << std::endl;
	delete[] arr;
	size = 0;
	max_size = 0;
	if (a.max_size > 0) {
		arr = new int[a.max_size];
		max_size = a.max_size;
		size = a.size;
		for (unsigned int i = 0; i < size; ++i) {
			arr[i] = a.arr[i];

		}

	}
	return *this;

}

int& MyVect::operator[](unsigned int i) const {
	if (i >= size) {
		throw index_out_of_bounds;

	}
	return arr[i];

}

MyVect& MyVect::push(int elem) {
	if (size == max_size) {
		throw out_of_space;

	}
	arr[size] = elem;
	++size;
	return *this;

}

unsigned int MyVect::get_size() const {
	return size;

}

MyVect::iter MyVect::begin() const {
	return arr;

}

MyVect::iter MyVect::end() const {
	return arr + size;

}

ostream& operator<<(ostream& out, const MyVect& v) {
	for (unsigned int i = 0; i < v.get_size(); ++i) {
		out << v[i] << " ";

	}
	return out;

}
