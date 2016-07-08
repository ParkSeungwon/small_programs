#include<atomic>
#include<thread>
#include<queue>
#include<iostream>
#include<mutex>
#include<condition_variable>
using namespace std;

//atomic<int> atom{0};
int atom = 0;
mutex mt;
condition_variable cv;
bool ready = false;
//unique_lock<mutex>  lock {mt};
void f() {
	unique_lock<mutex> lock{mt};
	cv.wait(lock, [](){return ready;});
	for(int i=0; i<10000; i++) {
		//mt.lock();
			atom++;
//		mt.unlock();
	}
}

int main()
{
	queue<thread> ths;
	for(int i=0; i<10; i++) ths.push(thread{f});
	{
		//unique_lock<mutex> lock{mt};
		ready = true;
	}
	cv.notify_all();
	while(!ths.empty()) {
		ths.front().join(); 
		ths.pop();
	}
	cout << atom << endl;
}
