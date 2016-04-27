#include <iostream>

float succeed(float p, int n)//p가 확률이고, n이 성공할 회차임.
{
	float r = 1.0;
	for(int i=0; i<n-1; i++) r *= 1-p;//(1-p)의 n-1승  
	r *= p; 
	return r;
}


int main()
{
	for(int i=3; i<7; i++) std::cout << succeed(0.2, i) << std::endl;//p가 0.2라 할 때
}
