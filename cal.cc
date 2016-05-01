#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char** argv)
{
	char c;
	float i, j;
	cout << "수식을 입력하세요." << endl;
	bool end = false;
	while(!end) {
	cin >> i >> c >> j;
		switch(c) {
		case '+': cout << i+j << endl; break;
		case '-': cout << i-j << endl; break;
		case '*': cout << i*j << endl; break;
		case '/': cout << i/j << endl; break;
		case '^': cout << pow(i, j) << endl; break;

		default: end = true;
		}
	}
}
