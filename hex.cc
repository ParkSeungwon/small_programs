#include <iostream>
#include<fstream>
using namespace std;

int main()
{
	ifstream f("a.txt");
	int i;
	f >> hex >> i;
	cout << i << endl;
}

