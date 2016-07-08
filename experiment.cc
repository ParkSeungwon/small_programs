#include<random>
#include<map>
#include<iostream>
using namespace std;

int main()
{
	uniform_int_distribution<> d(1, 20);
	random_device r;

	map<int, int> m1, m2;
	for(int j=0; j<10000; j++) {
		for(int i=0; i<20; i++) m1[d(r)]++;
		m2[m1.size()]++;
		m1.clear();
	}
	for(auto& a : m2) cout << a.first << ':' << a.second << endl;
}
