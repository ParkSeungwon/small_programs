#include<complex>
#include<iostream>
using namespace std;

int main()
{
	complex<float> p1 {-1, 0};
	complex<float> p2 {2, 1};
	complex<float> p3 {3, 4};

	p1 = p2 - p1;
	p2 = p3 - p2;

	auto theta = arg(p2);
	if(theta > arg(p1) + M_PI) theta -= 2 * M_PI;
	if(theta < arg(p1) - M_PI) theta += 2 * M_PI;
	cout << (theta - arg(p1) > 0 ? 'L' : 'R');
}
