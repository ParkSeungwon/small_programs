#include<type_traits>
#include<iostream>
#include<string>
using namespace std;

class Any
{
public:
	string s;
	int i;
	static const bool is_int = true;
	enable_if<true, bool>::type f() { return i;}
};


int main()
{}
