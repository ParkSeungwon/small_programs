#include<iostream>
using namespace std;

int fee(int kw, char purpose) {
	int r;
	if(kw > 600) r = 100 * 300 + 150 * 300 + (kw - 600) * 200;
	else if(kw > 300) r = 100 * 300 + (kw - 300) * 150;
	else r = 100 * kw;
	switch(purpose) {
	case 'R': return r * 1.1;
	case 'I': return r * 1.2;
	case 'C': return r * 1.3;
	}
}

int main()
{
	cout << fee(450, 'I') << endl;
}
