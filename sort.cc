#include<algorithm>
#include<random>
#include<iostream>
using namespace std;

int main() {
	uniform_int_distribution<> di(0, 100);
	random_device rd;
	int ar[100];
	for(int i=0; i<100; i++) ar[i] = di(rd);
	for(int i=0; i<100; i++) cout << ar[i] << ' ';
	cout << endl;
	sort(ar, ar+100, [](int a, int b){ return a<b;});
	for(int i=0; i<100; i++) cout << ar[i] << ' ';
}
