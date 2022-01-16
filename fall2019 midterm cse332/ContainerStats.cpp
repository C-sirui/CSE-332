#include "ContainerStats.h"

ContainerStats::ContainerStats(int minimum, int maximum, int total) : min(minimum),
max(maximum), sum(total)
{
	std::cout << "ContainerStats constructor Version 1" << std::endl;
}

ContainerStats::ContainerStats(const ContainerStats& cs) : min(cs.min), max(cs.max),
sum(cs.sum)
{
	std::cout << "ContainerStats constructor Version 2" << std::endl;
}

ContainerStats::~ContainerStats()
{
	std::cout << "ContainerStats destructor" << std::endl;
}

int ContainerStats::get_min() const {
	return min;
}

int ContainerStats::get_max() const {
	return max;
}

int ContainerStats::get_sum() const {
	return sum;
}

bool ContainerStats::operator<(const ContainerStats& other) const {
	return min < other.min;
}

void ContainerStats::print_range() const {
	std::cout << "Range is: " << max - min << std::endl;
}

void ContainerStats::print() const {
	std::cout << "Statistics:" << std::endl;
	std::cout << "min: " << min << std::endl;
	std::cout << "max: " << max << std::endl;
	std::cout << "sum: " << sum << std::endl;
}

