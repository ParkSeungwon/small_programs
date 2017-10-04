#include<sstream>
#include<iostream>
using namespace std;

int main()
{
	int a=1;
	int b=2;
	char c='a';
	char d='b';
	stringstream ss;
	ss << a << b << c << d;
	cout << ss.str();
}
