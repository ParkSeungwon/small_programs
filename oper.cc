#include <iostream>
using namespace std;

class Num 
{
public:
	Num(int i) {a=i;}
	int a;
	int operator+(Num b) {return 2*a + b.a;}
};

int main()
{
	Num a(3);
	Num b(5);
	cout << a+b << endl;
}
