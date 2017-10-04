#include<iostream>
using namespace std;

class A {
public:
	int i=1;
	void show(){cout << "from A : "<< i << endl;}
};

class B : public A {
public:
	int i=2;
	void show(){cout << "from B : "<< i << endl;}
};
class C : public A {
public:
	int i=3;
};

int main()
{
	A a;
	B b;
	C c;
	b.show();
	b.A::show();
	c.show();
}
