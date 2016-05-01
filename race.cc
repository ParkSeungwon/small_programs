#include <iostream>
#include <vector>
#include <thread>
#include <functional>
using namespace std;
void f() {this_thread::sleep_for(chrono::seconds(1));}
void func(int& counter)
{
	for(int i=0; i<10000; i++) ++counter;
}

int main()
{
	int counter = 0;
	vector<thread> threads;
	for(int i=0; i<10; i++) {
		threads.push_back(thread{func, ref(counter)});
	}
	//for(auto& t : threads) t.join();
	cout << "Result = " << counter << endl;
	for(auto& a : threads) a.join();
	return 0;
}
