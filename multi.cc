#include<iostream>
using namespace std;

int main()
{
	short n[2][50] {};
	short r[100] {};

	int i = -1, j = -1;
	char c = ' ';
	while(c != '\n') {
		cin >> noskipws >> c;
		n[0][++i] = c - '0';
	}
	c = ' ';
	while(c != '\n') {
		cin >> noskipws >> c;
		n[1][++j] = c - '0';
	}
	for(int k=1; k<=i; k++) {
		for(int l=1; l<=j; l++) {
			r[k+l-2] += n[0][i-k] * n[1][j-l];
		}
	}
	for(int k=0; k<99; k++) {
		r[k+1] += r[k] / 10;
		r[k] %= 10;
	}
	if(r[i+j-1] != 0) cout << r[i+j-1];
	for(int k=i+j-2; k>=0; k--) cout << r[k];
	cout << endl;
}
