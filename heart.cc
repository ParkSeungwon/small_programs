#include <iostream>
using namespace std;

int main()
{
	const char *a, *b, *t;
	a = "this is a";
	b = "this is b";
	cout << a << endl << b << endl;
	t = b;
	b = a;
	a = t;
	cout << a << endl << b << endl;

}
