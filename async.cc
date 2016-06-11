#include <future>
#include<thread>
#include<chrono>
#include<vector>
#include <iostream>
using namespace std;
//void func1() {
//	this_thread::sleep_for(chrono::seconds(1));
//}
void pr(int n) {
	this_thread::sleep_for(chrono::seconds(n));
	switch (n) {
		case 1: cout << "heart" << endl; break;
		case 2: cout << "star" << endl; break;
		case 3: cout << "circle" << endl; break;
	}
}

int main()
{
	int n = 0;
	vector<future<void>> v;
	while(n != 4) {
		cin >> n;
		v.push_back(async(launch::async, pr, n));
	}
	for(auto& a : v) a.get();
}
