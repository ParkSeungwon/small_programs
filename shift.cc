#include <iostream>
using namespace std;

int main()
{
	int i = 65537;
	i <<= 8;
	i >>= 24;
	cout << i << endl;
}
