#include <iostream>
#include<cstdlib>
using namespace std;

template <typename T> struct V {
	T s;
};

V<string>* f() {
	V<string>* p = new(V<string>);
	string s = "fjsl";
	p->s = s;
	return p;
}

int main()
{
	cout << f()->s;
}
