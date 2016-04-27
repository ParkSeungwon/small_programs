#include <iostream>
using namespace std;
int main ()
{
	int a[5][6][7];

	int* b = &(a[0][0][0]);
	int* c = &(a[3][4][5]);
	cout << c - b ;
}
