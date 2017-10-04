#include<iostream>
#include<memory>
using namespace std;

int main()
{
	int i = 10;
	int* p = &i;
	shared_ptr<int> sp;
	sp = make_shared<int>(*p);
	cout << *sp << endl;
}
