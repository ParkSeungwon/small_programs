#include<iostream>
using namespace std;

int A(int m, int n) {
	if(m == 0) return n+1;
	if(n == 0) return A(m-1, 1);
	return A(m-1, A(m, n-1));
}

int main() 
{
	cout << A(3,2) << endl;
	for(int i=1; i<20; i++) cout << A(3,i) << endl;	
}


