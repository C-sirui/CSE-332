Answer studio 16 questions here

Team members: Jack Li, Ryan Chen

Q2:
class AbstractFile{
public:
	virtual void read() = 0;
	virtual int write(vector<char>) = 0;
	virtual int append(vector<char>) = 0;
	virtual unsigned int getSize() = 0;
	virtual string getName() = 0;
};

Q3:
a, interface inheritance
b, it should be public

Q4:
test1:
	TextFile txt("test");
	txt.read();
	vector<char> input;
	input.push_back('b');
	input.push_back('e');
	input.push_back(' ');
	input.push_back('p');
	input.push_back('o');
	input.push_back('l');
	input.push_back('i');
	input.push_back('t');
	input.push_back('e');
	txt.write(input);
	txt.read();

	output:
		be polite

	read() and wirte() are fine

test2:
	cout << txt.getName() << " has size: " << txt.getSize() << endl;
	
	output:
		test has size: 9

	getname() and getSize() are fine

test3:
	vector<char> append;
	append.push_back('\n');
	append.push_back('g');
	append.push_back('o');
	append.push_back('o');
	append.push_back('d');
	append.push_back(' ');
	append.push_back('b');
	append.push_back('o');
	append.push_back('y');
	txt.append(append);
	txt.read();

	coutput:
		be polite
		good boy

	append() is fine

Q5:
I do not really understand this question
Only one file type TextFile is defined.
		

	


