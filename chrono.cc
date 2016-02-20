#include <chrono>
#include <ctime>
#include <iostream>
using namespace std;
using namespace std::chrono;

int main () 
{
	seconds sec(1);
	hours hr(1);
	milliseconds ms(1);
	cout << (hr + sec).count() << endl;
	auto now = system_clock::now();
	auto tp = system_clock::to_time_t(now);
	auto t = ctime(&tp);
	cout << t << endl;
}

