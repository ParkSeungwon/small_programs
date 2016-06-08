#include<chrono>
#include<random>
#include<thread>
#include<iostream>
using namespace std;
using namespace std::chrono;

int main()
{
	uniform_int_distribution<> di(0, 10);
	random_device rd;
	while(true) {
		this_thread::sleep_for(seconds(3));
		cout << di(rd) << endl;
	}
}
