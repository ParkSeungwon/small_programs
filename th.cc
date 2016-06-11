#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <vector>
using namespace std;

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
	vector<thread> v;
	int n;
	while(1) {
		cin >> n;
		v.push_back(thread(pr, n));
	}
}
