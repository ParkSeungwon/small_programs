#include <iostream>
#include<cmath>
using namespace std;

int factorial(int i) {
	if(i == 1) return 1;
	else return i * factorial(i-1);
}

float exp(float x) {
	float r = 1;
	for(int i=1; i<21; i++) r += pow(x, i) / factorial(i);
	return r;
}

int main()
{
	cout << exp(1) << endl;
}
