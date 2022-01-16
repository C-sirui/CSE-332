Q2
Ryan Chen
Asychronous


Q2
class student {
private:
    unsigned int id_;
    string name_;
public:
    student(unsigned int id, string name);
    friend ostream& operator<<(ostream& os, const student& st);
    friend bool operator< (const student& a, const student& b);
};
student::student(unsigned int id, string name) : id_(id), name_(name) {}

Q3
    vector<student> members;
    student a(1, "one");
    student b(2, "two");
    student c(3, "three");
    members.push_back(a);
    members.push_back(b);
    members.push_back(c);
    ostream_iterator<student> o(cout);
    copy(members.begin(), members.end(), o);
Q3.1
    ostream_operator << need to be overloaded.

Q4
    sort(members.begin(), members.end());
Q4.1
    bool operator< need to be overloaded.

Q5
    C:\Users\poi\source\repos\cse332s-fl21-wustl\studio11-asynchronous\studio11\ConsoleApplication1\Debug> ConsoleApplication1.exe txt.txt
ID: 3, NAME: three
ID: 1, NAME: one
ID: 2, NAME: two
sorted
ID: 1, NAME: one
ID: 2, NAME: two
ID: 3, NAME: three
after reading inputfile:
ID: 1, NAME: one
ID: 2, NAME: two
ID: 3, NAME: three
ID: 12, NAME: Jack
ID: 11, NAME: Bob
ID: 10, NAME: Alice
sorted:
ID: 1, NAME: one
ID: 2, NAME: two
ID: 3, NAME: three
ID: 10, NAME: Alice
ID: 11, NAME: Bob
ID: 12, NAME: Jack
Q5.1
    Don't really need an extra overloading to accomplish this.


