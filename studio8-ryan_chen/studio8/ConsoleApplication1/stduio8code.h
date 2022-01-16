#pragma once

class test{	
public:
	test ();
	int getx()const {
		return x_;
	};
	int gety()const {
		return y_;
	};
	test& setx(int x) {
		x_ = x;
		return *this;
	}
	int x;
	int y;
private:
	int x_;
	int y_;

};

