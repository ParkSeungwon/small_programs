#include<iostream>
#include<chrono>
#include<thread>
using namespace std;
using namespace std::chrono;

int main()
{
	system_clock::time_point start = system_clock::now();

	while(true) {
		this_thread::sleep_for(seconds(1));
		system_clock::time_point end = system_clock::now();
		cout << "elapsed time = " ;
		cout << duration_cast<microseconds>(end-start).count();
		cout << " miliseconds\r" << flush;
	}
}
