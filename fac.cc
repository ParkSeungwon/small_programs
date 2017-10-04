#include<iostream>
using namespace std;

int factorial(int n) {
	int r = 1;
	for(int i=1; i<=n; i++) r *= i;
	return r;
}

int fact(int n) {
	return n == 1 ? 1 : n * fact(n-1);
}

int main() {
	cout << factorial(10) << ' ' << fact(10);
}
