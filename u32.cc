#include<iostream>
#include<initializer_list>
using namespace std;

void f(initializer_list<int> l) {
	cout << *l.begin();
	for(auto& a : l) cout << a << ' ';
}

int main()
{
	auto a = {2,3,4,5,6};
	f(a);
}
