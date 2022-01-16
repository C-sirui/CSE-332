
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator> 
#include <fstream>
#include <sstream>

using namespace std;

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

ostream& operator<<(ostream& os, const student& st)
{
    os << "ID: " << st.id_ << ", " << "NAME: " << st.name_ << endl;
    return os;
}

bool operator<(const student& a, const student& b)
{
    return a.id_ < b.id_;
}


int main(int argc, char* argv[])
{
    // Q3
    vector<student> members;
    student c(3, "three");
    student a(1, "one");
    student b(2, "two");
    members.push_back(c);
    members.push_back(a);
    members.push_back(b);
    ostream_iterator<student> o(cout);
    copy(members.begin(), members.end(), o);

    // Q4
    cout << "sorted" << endl;
    sort(members.begin(), members.end());
    copy(members.begin(), members.end(), o);

    // Q5
    if (argc != 2) {
        cout << "invalid input, run the program with one input file" << endl;
        return -1;
    }
    ifstream file;
    file.open(argv[1]);
    string line, kb;
    unsigned int jb;
    while (getline(file,line)){
        stringstream in(line);
        if (in >> jb >> kb) {
            student temp(jb,kb);
            members.push_back(temp);

        }
        else {
            cout << "invalid content in inputfile" << endl;
        }
    }
    cout << "after reading inputfile: " << endl;
    copy(members.begin(), members.end(), o);
    cout << "sorted: " << endl;
    sort(members.begin(), members.end());
    copy(members.begin(), members.end(), o);
    return 0;

}

