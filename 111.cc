#include<iostream>
using namespace std;

int main()
{
	const char* p[] = {"abfsfsdfs", "fds"};
	cout << &p[0] << ' ' << &p[1] << endl;
	cout << *(p+2) << endl;
}
