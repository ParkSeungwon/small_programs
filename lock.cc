#include <thread>
#include <mutex>
#include <iostream>
#include <deque>
#include <future>
#include <condition_variable>
using namespace std;

deque<int> q;
mutex mu;
condition_variable cond;

void function_1()
{
	int count = 10;
	while(count > 0) {
		unique_lock<mutex> locker(mu);
		q.push_front(count);
		locker.unlock();
		cond.notify_one();
		cond.notify_all();
		this_thread::sleep_for(chrono::seconds(1));
		count--;
	}
}

void function_2()
{
	int data = 0;
	while(data != 1) {
		unique_lock<mutex> locker(mu);
		cond.wait(locker, [](){ return !q.empty();});
		data = q.back();
		q.pop_back();
		locker.unlock();
		cout << "t2 git a value from t1: " << data << endl;
	}
	
}


int main ()
{
	thread t1(function_1);
	thread t2(function_2);

	auto f = async([](){return 3;});
	cout << f.get();
	t1.join();
	t2.join();
	return 0;
}
