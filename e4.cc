#include<iostream>
using namespace std;

int n[4] {1,2,3,4};

int e(int n[4]) {
	for(int i=0; i<4; i++) cout << n[i] << ' ';
}

int main()
{
	e(n);
}
