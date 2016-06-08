#include <fstream>
#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
	if(argc < 3) {
		cout << "usage : " << argv[0] << " [text file] row" << endl;
		return 0;
	}

	ifstream f(argv[1]);
	int a = stoi(argv[2]);
	char c;
	int i = 0;
	while(f >> noskipws >> c) {
		i++;
		if(c == '\n' || c == '\t') cout << ' ';
		else cout << c; 
		if(i % a == 0) cout << '\n';
	}
}

