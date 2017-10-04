#include <chrono>
#include <iostream>
#include <cmath>
using namespace std::chrono;
using namespace std;

void test()
{
	for(long i=0; i<10000000; ++i) sqrt(123.456L);
}

int main()
{
	system_clock::time_point start, end;
	start = system_clock::now();
	test();
	end = system_clock::now();
	duration<float> sec = end - start;
	cout << "took " << sec.count() << " seconds" << endl;
	start = start + seconds(100);
	time_t tt = system_clock::to_time_t(start);
	cout << ctime(&tt); 
}
