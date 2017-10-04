#include<iostream>
#include<sstream>
#include<string>
using namespace std;

int main()
{
	string s = "2013-01-01 00:05:00";
	char c;
	stringstream ss;
	ss << s;
	int k;
	for(int i=0; i<3; i++) {
		ss >> k;
		ss >> c;
		cout << k << endl;
	}
	for(int i=0; i<3; i++) {
		ss >> k;
		ss >> c;
		cout << k << endl;
	}


}
