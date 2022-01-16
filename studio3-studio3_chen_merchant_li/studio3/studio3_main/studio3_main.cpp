#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	for (auto i = 0; i < argc; ++i) {
		for (auto p = argv[i]; *p != '\0'; ++p) {
			cout << *p << endl;
		}
	}
	return 0;
}

