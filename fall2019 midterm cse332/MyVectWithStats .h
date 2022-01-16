#pragma once

#ifndef MYVECTWITHSTATS_H
#define MYVECTWITHSTATS_H

#include "containerstats.h"
enum vect_exceptions { index_out_of_bounds = 1, out_of_space };

class MyVectWithStats : public ContainerStats {

	int* arr;
	unsigned int size;
	unsigned int max_size;
	typedef int* iter;
public:
	MyVectWithStats() = delete;
	MyVectWithStats(unsigned int s, int initial_min, int initial_max, int initial_sum);
	MyVectWithStats(const MyVectWithStats& a);

	~MyVectWithStats();

	int& operator[](unsigned int i) const;

	MyVectWithStats& push(int elem);
	unsigned int get_size() const;

	iter begin() const;
	iter end() const;

	virtual ContainerStats& insert_and_update(int elem);
	void print_range() const;
	virtual void print() const;
};

std::ostream& operator<<(std::ostream& out, const MyVectWithStats& v);

#endif // !1