#include "MyVectWithStats .h"

using namespace std;

MyVectWithStats::MyVectWithStats(unsigned int s, int initial_min, int initial_max, int initial_sum) : 
	ContainerStats(initial_min, initial_max, initial_sum), arr(nullptr), size(0), max_size(s) {
	std::cout << "MyVectWithStats constructor Version 1" << std::endl;
	arr = new int[max_size];
}

MyVectWithStats::MyVectWithStats(const MyVectWithStats& a) : ContainerStats(a),
arr(nullptr), size(0), max_size(0) {
	std::cout << "MyVectWithStats constructor Version 2" << std::endl;
	if (a.max_size > 0) {
		arr = new int[a.max_size];
		size = a.size;
		max_size = a.max_size;
		for (unsigned int i = 0; i < size; ++i) {
			arr[i] = a.arr[i];
		}
	}
}

MyVectWithStats::~MyVectWithStats() {
	std::cout << "MyVectWithStats destructor" << std::endl;
	delete[] arr;
}

int& MyVectWithStats::operator[](unsigned int i) const {
	if (i >= size) {
		throw index_out_of_bounds;
	}
	return arr[i];
}

MyVectWithStats& MyVectWithStats::push(int elem) {
	if (size == max_size) {
		throw out_of_space;
	}
	arr[size] = elem;
	++size;
	return *this;
}

unsigned int MyVectWithStats::get_size() const {
	return size;
}

MyVectWithStats::iter MyVectWithStats::begin() const {
	return arr;
}

MyVectWithStats::iter MyVectWithStats::end() const {
	return arr + size;
}

ContainerStats& MyVectWithStats::insert_and_update(int elem) {
	if (size == 0) {
		min = elem;
		max = elem;
		sum = elem;
		push(elem);
		return *this;
	}
	if (elem < min) {
		min = elem;
	}
	if (elem > max) {
		max = elem;
	}
	sum += elem;
	push(elem);
	return *this;
}

void MyVectWithStats::print_range() const {
	cout << "valid indices are 0-" << size - 1 << endl;
}

void MyVectWithStats::print() const {
	cout << *this << endl;
	ContainerStats::print();
}

ostream& operator<<(ostream& out, const MyVectWithStats& v) {
	for (unsigned int i = 0; i < v.get_size(); ++i) {
		out << v[i] << " ";
	}
	return out;
}
