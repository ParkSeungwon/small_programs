#include<iostream>
using namespace std;

int main()
{
	char ar[10][10];

	int k = 0;
	for(int i=0; i<10; i++) for(int j=0; j<10; j++) ar[i][j] = k++;
	for(int i=0; i<10; i++) for(int j=0; j<10; j++) cout << +*(*(ar+i)+j) << ' ';
}
