#include <iostream>
using namespace std;

int count(long n)
{
	if(n == 1) return 0;
	if(n%2 == 0) n /= 2;
	else n = 3*n +1;
	return 1 + count(n);
}

int main(int argc, char** argv)
{
	if(argc < 3) return 0;
	int i = atoi(argv[1]);
	int j = atoi(argv[2]);
	int b=0;
	for(int k=i; k<=j; k++) 
		if(count(k) > b) cout << k << "count " << (b = count(k)) << endl;
}

