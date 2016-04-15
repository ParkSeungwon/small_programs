#include <list>
#include <iostream>
using namespace std;

int main() {
	list<list<int>> li {
		{1, 2, 3},
		{1,2},
		{3}
	};
	li.push_back({1,4,5});
	for(auto &a : li) for(auto &b : a) cout << b;
}
