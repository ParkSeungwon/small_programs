#include <iostream>
#include<thread>
#include<chrono>
#include <random>
#include<future>
using namespace std;
using namespace std::chrono;

int main()
{
	uniform_int_distribution<> d(0,9);
	random_device r;

	bool ok=true;
	auto a = async(launch::async, [&ok]() {
			char c; 
			system("stty -echo");
			cin >> c; 
			system("stty echo");
			cout << endl;
			ok = false;
			});

	while(ok) {
		this_thread::sleep_for(milliseconds(50));
		cout << d(r) << '\r' << flush;

	}
	a.get();
}
