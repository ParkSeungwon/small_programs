#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	if(argc < 2) {
		cout << "usage : " << argv[0] << " number(1~10)" << endl;
		return 0;
	}
	int arr[10][10];
	int n = atoi(argv[1]);
	int m = n;
	int j=-1, k=0, l=1;
	for(int i=0; i<n; i++) arr[++j][k] = l++;
	while(n > 1) {
		n--;
		for(int i=0; i<n; i++) arr[j][++k] = l++;
		for(int i=0; i<n; i++) arr[--j][k] = l++;
		n--;
		for(int i=0; i<n; i++) arr[j][--k] = l++;
		for(int i=0; i<n; i++) arr[++j][k] = l++;
	}
	for(int j=0; j<m; j++) {
		for(int i=0; i<m; i++) cout << arr[j][i] << ' ';
		cout << endl;
	}
}


