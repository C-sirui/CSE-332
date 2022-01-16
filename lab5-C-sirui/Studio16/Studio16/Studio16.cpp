// Studio16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "..\..\\SharedCode\TextFile.h"
#include <iostream>
using namespace std;


int main(unsigned argc, char* argv[])
{
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
	cout << txt.getName() << " has size: " << txt.getSize() << endl;
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

	


	return 0;
}


