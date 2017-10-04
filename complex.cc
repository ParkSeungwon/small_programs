#include<complex>
#include<iostream>
using namespace std;

class Point : public complex<float>
{
public:
	Point(complex<float> im) : complex<float>(im.real(), im.imag()) {}
};

int main()
{
	Point a{{3, -4}};
	Point b{{2, 3}};
	cout << arg(b -a) << endl;
	cout << a << endl;
}


