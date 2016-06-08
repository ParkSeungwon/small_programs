#include <memory>
#include<iostream>
using namespace std;

int main()
{
	auto a = make_shared<int>(10);
	cout << *a << ' ';
}

