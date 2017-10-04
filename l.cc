#include<iostream>
#include<cstdlib>
#include"listack.h"
using namespace std;

int main()
{
	try {
		Listack<int> s;
		s.push(4);
		s.insert(5);
		s.insert(4);
		s.push(2);
		s.show();
		cout << s.pop_back() << endl;
		s.push(3);
		s.push(3);
		s.show();
		s.del_if([](int n){return n % 2;});
		s.show();
		Listack<int> li;
		while(!s.is_empty()) li.insert(s.pop());
		li.show();
	} catch (const char* e) {
		cout << e << endl;
	}
}
