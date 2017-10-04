#include<iostream>
#include<numeric>
using namespace std;

int main()
{
	int ar[10] = { 1, 2, 3,4, 5,6,7,8,9,0};

	//int* p = ar;
	int (*q)[2] = reinterpret_cast<int(*)[2]>(ar);

	for(int i=0; i<5; i++) cout << **(q+i) << ' ';
	cout << endl << inner_product(*q, *q + 3, ar, 0) << endl;
}
