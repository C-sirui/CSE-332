#pragma once

#ifndef TOOLS_H
#define TOOLS_H

class Detector
{
public:
	static unsigned int COUNT;
	unsigned int id;
	Detector();
	~Detector();
};

class Wrapper
{
private:
	Detector* detector_p;
	bool b_;
public:
	Wrapper();
	Wrapper(const Wrapper& w);
	Wrapper& operator=(const Wrapper& w);
	virtual ~Wrapper();
	Wrapper(Wrapper&& w);
	Wrapper& operator=(Wrapper&& w);
};


#endif // !TOOLS_H
