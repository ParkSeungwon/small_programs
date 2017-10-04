#include<iostream>
using namespace std;

int f() {return 3;}
int f2() {
	static int n = f();
	n++;
	return n;
}
int main()
{
	f2();
	f2();
	cout << f2();
}

