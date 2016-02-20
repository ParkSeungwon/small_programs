#include <iostream>
#include <fstream>
#include <thread>
#include <string>
#include <mutex>
using namespace std;

mutex mu;
void shared_print(string msg, int id) {
	lock_guard<mutex> guard(mu);
//	mu.lock();
	cout << msg << id << endl;
//	mu.unlock();
}

class LogFile {
	mutex mutex_;
	ofstream f;
public:
	LogFile() {
		f.open("log.txt");
	}
	void shared_print(string id, int value) {
		lock_guard<mutex> locker(mutex_);
		f << "From " << id << ": " << value << endl;
	}
};

void function_1(LogFile& log) {
	for(int i=0; i<100; i++) log.shared_print(string("from thread: "), i);
}


int main() {
	LogFile log;
	
	thread t1(function_1, ref(log));
	for(int i=0; i<100; i++) log.shared_print(string("from main: "), i);
	t1.join();
	return 0;
}
