#include<thread>
#include <chrono>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;
using namespace std::chrono;

int main () 
{
	while(true) {
		auto tp = system_clock::to_time_t(system_clock::now());
		string t = ctime(&tp);
		t.back() = '\r';
		cout << t << flush;
		this_thread::sleep_for(milliseconds(100));
	}
}
