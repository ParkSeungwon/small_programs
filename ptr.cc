#include <iostream>
using namespace std;

int main() {
	int x=2;
	int *p;
	int **y;
	p=&x;
	y=&p;
	cout << p << endl;
	cout << y << endl;
}

