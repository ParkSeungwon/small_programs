#include<fstream>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	ifstream f1("memo1.txt");
	string r;
	char c;
	while(!(f1 >> noskipws >> c).eof()) r += c;
	cout << r;

}
