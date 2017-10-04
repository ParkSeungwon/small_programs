#include<iostream>
using namespace std;

class A {
public:
	int a;
	A(int n) : a(n) {}
	//A() {a = 1;}
};

int main()
{
	A a(1), b(2);
	a = b;
	cout << a.a << endl;
}


