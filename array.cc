#include<iostream>
using namespace std;

int main()
{
	int A[3][4];
	int* p = &A[0][3];
	int* q = A[0];
	for(int* p = *A, i = 0;i<12 ;p++, i++) *p = i;
	cout << *(p+1) << endl;
	cout << *(q+1) << endl;
	cout << *A[1] << endl;
	cout << +*A << endl;
	cout << +*A << endl;
	cout << +&A[0] << endl;
	cout << +*A[0] << endl;

}
