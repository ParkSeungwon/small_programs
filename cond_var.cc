#include<thread>
#include<deque>
#include<condition_variable>
#include<iostream>
using namespace std;

condition_variable cond;
mutex mu;
deque<int> q;
void f() {
	int count = 10; 
	while(count > 0) {
		unique_lock<mutex> locker(mu);
		q.push_front(count);
		locker.unlock();
		cond.notify_one();
		this_thread::sleep_for(chrono::seconds(1));
		count--;
	}
}

void f2() {
	int data = 0;
	while(data != 1) {
		unique_lock<mutex> locker(mu);
		cond.wait(locker, [](){return !q.empty();});
		data = q.back();
		q.pop_back();
		locker.unlock();
		cout << "t2 got a value from t1: " << data << endl;
	}
}

int main()
{
	thread t1(f);
	thread t2(f2);
	t1.join();
	t2.join();
}
