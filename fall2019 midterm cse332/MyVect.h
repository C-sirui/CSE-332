
#include<iostream>

class MyVect {
protected:
	int* arr;
	unsigned int size;
	unsigned int max_size;
	typedef int* iter;
public:
	MyVect() = delete;
	MyVect(unsigned int s);
	MyVect(const MyVect& a);

	~MyVect();

	MyVect& push(int elem);
	unsigned int get_size() const;

	iter begin() const;
	iter end() const;

	MyVect& operator=(const MyVect& a);
	int& operator[](unsigned int i) const;

};

std::ostream& operator<<(std::ostream& out, const MyVect& v);
