#include <iostream>
using namespace std;

int factorial(int n) 
{
	if(n == 1) return 1;
	else return n * factorial(n-1);
}

int nPr(int n, int r) { return factorial(n)/factorial(n - r); }
int nCr(int n, int r) { 
	if(r == 0 || r == n) return 1; 
	return nPr(n, r)/factorial(r);
}

int main(int argc, char** argv)
{
	if(argc < 2) return 0;
	int n = atoi(argv[1]);
	for(int r = 0; r <= n; r++) 
		cout << nCr(n, r) << "a^" << n-r << "b^" << r << '+';
	cout << endl;
}
