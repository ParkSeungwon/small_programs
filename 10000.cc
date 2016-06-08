#include<iostream>
#include<chrono>
#include<fstream>
#include<random>
#include<unordered_set>
using namespace std;
using namespace std::chrono;

int main()
{
	uniform_int_distribution<> di(0,5000);
	random_device rd;
	unordered_set<int> s, e;

	system_clock::time_point start = system_clock::now();

	for(int i=0, j; i<10000; i++) {
		j = di(rd);
		if(s.find(j) != s.end()) e.insert(j); 
		else s.insert(j);
	}
	ofstream f1("num.txt");
	ofstream f2("error.txt");
	for(auto& a : s) f1 << a << ' ';
	for(auto& a : e) f2 << a << ' ';

	system_clock::time_point end = system_clock::now();

	cout << "elapsed time = " ;
	cout << duration_cast<microseconds>(end-start).count();
	cout << " miliseconds" << endl;
}
