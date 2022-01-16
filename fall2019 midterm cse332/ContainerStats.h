#pragma once
#include<iostream>

class ContainerStats {
public:
	ContainerStats(int minimum, int maximum, int total);
	ContainerStats(const ContainerStats& cs);

	virtual ~ContainerStats();

	int get_min() const;
	int get_max() const;
	int get_sum() const;

	bool operator<(const ContainerStats& other) const;

	void print_range() const;

	virtual void print() const;

	virtual ContainerStats& insert_and_update(int elem) = 0;

protected:
	int min;
	int max;
	int sum;
};