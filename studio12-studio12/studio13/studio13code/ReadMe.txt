Q1
Ryan Chen
studio13

Q2
class detect {
private:
	unsigned int cnt_;
	static unsigned int wut;
public:
	detect() {
		cnt_ = wut;
		wut++;
		cout << "detect" << ": " << this << ", count: " << cnt_ << endl;
	};
	~detect() {
		cout << "~detect" << ": " << this << ", count: " << cnt_ << endl;
	}
};
unsigned int detect::wut = 0;