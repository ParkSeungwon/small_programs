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
	system_clock::time_point start = system_clock::now();
	test();
	duration<double> sec = system_clock::now() - start;
	cout << "took " << sec.count() << " seconds" << endl;
}
