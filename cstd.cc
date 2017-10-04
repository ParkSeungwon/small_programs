#include<cstdarg>
#include<condition_variable>
#include<thread>
#include<iostream>
#include<atomic>
#include<mutex>
using namespace std;

int sum(int n, int k, ...) 
{
	char b[30];
	int i, val = 0;
	va_list vl;
	val += n;
	va_start(vl, n);
	vsprintf(b, "%d %d %d %d", vl);
	printf("%s", b);
	va_start(vl, k);
	while(i = va_arg(vl, int)) val += i;
	va_end(vl);
	return val;
}

mutex m;
atomic_flag flag = ATOMIC_FLAG_INIT;
atomic<bool> ready{false};
condition_variable cv;

void print(int n, char c) 
{
	//m.lock();
//	lock_guard<mutex> lock(m);
	//while(!ready);
	unique_lock<mutex> lock(m);
	cv.wait(lock);
	for(int i=0; i<1000000; i++) ;
	for(int i=0; i<100; i++) cout << c;
	if(!flag.test_and_set()) cout << c << "won";
	//flag.clear();
//	m.unlock();
}


int main()
{
	thread t1(print, 100, 'a');
	thread t2(print, 100, 'c');
	this_thread::sleep_for(chrono::seconds(1));
	cv.notify_one();
	t1.join();
	t2.join();
}
