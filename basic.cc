#include<iostream>
//#define NDEBUG 
#include<cassert>
using namespace std;

int main()
{
	for(int j=5; j>0; j--) {
		for(int i=0; i<j-1; i++) cout << ' ';
		for(int i=6-j; i>0; i--) cout << i;
		cout << endl;
	}
	assert(34 == 23);
}
