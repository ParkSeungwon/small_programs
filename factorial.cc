#include <iostream>
#include<cmath>
using namespace std;

int factorial(int i) {
	return i==1 ? 1 : i*factorial(i-1);
}

float exp(float x) {
	float r = 1;
	for(int i=1; i<21; i++) r += pow(x, i) / factorial(i);
	return r;
}

int main(int c, char** v)
{

	char ar[stoi(v[1])];
	int i{'a'};
	for(auto& a : ar) a = i++;
	for(auto& a : ar) cout << a << ' ';
	cout << factorial(stoi(v[1])) << endl;
	cout << exp(1) << endl;
}
