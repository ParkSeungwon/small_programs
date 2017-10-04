#include<ctime>
#include<iostream>
using namespace std;

int main()
{
	auto t = time(0);
	srand(t);
	auto tm = localtime(&t);
	cout << tm->tm_year << ' ' << tm->tm_mon << ' ' << tm->tm_mday << endl;
	cout << ctime(&t);
	cout << rand() << endl;
}
