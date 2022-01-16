#include <iostream>
#include<vector>
#include <sstream>
#include<string>
using namespace std;

int main(int argc, char * argv[])
{
	ostringstream argsout;
	for (int q = 0; q < argc; ++q) {
		argsout << argv[q] << " ";
		istringstream argsin(argsout.str());
		string a = " ";
		argsin >> a;
		cout << a << endl;
	}
	return 0;


	//vector<char*> name;
	//for (int i = 0; i < argc; ++i) {
	//	name.push_back(argv[i]);
	//	cout << name[i] << endl;
	//}

	//unsigned int sample[2][3][5] = {0};
	//for (int x = 0; x < 2; ++x) { 
	//	for (int y = 0; y < 3; ++y) {
	//		for (int z = 0; z < 5; ++z) {
	//			sample[x][y][z] = x * y * z;
	//			cout << x << y << z << ":    " << sample[x][y][z] << endl;
	//		}
	//	}
	//}


	return 0;
}


