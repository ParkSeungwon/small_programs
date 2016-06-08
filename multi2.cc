#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
	if(argc < 3) {
		cout << "usage " << argv[0] << " number number" << endl;
		return 0;
	}
	short r[100] {};

	int i = 0, j = 0;
	char* p = argv[1];
	while(*p != '\0') {
		*p++ -= '0';
		i++;
	}
	p = argv[2];
	while(*p != '\0') {
		*p++ -= '0';
		j++;
	}
	for(int k=0; k<i; k++) {
		for(int l=0; l<j; l++) {
			r[k+l] += argv[1][i-k-1] * argv[2][j-l-1];
		}
	}
	for(int k=0; k<i+j; k++) {
		r[k+1] += r[k] / 10;
		r[k] %= 10;
	}
	if(r[i+j-1] != 0) cout << +r[i+j-1];
	for(int k=i+j-2; k>=0; k--) cout << +r[k];
	cout << endl;
}
