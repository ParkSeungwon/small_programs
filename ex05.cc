#include"listack.h"
using namespace std;

int fibo(int n) {
	if(n < 2) return n;
	else return fibo(n-1) + fibo(n-2);
}

int main()
{
	Listack<int> l1, l2;
	for(int i=0; i<10; i++) l1.push(i);
	for(int i=0; i<10; i++) l2.push(l1.pop());
	for(int i=0; i<10; i++) cout << l2.pop() << ' ';

	cout << endl << fibo(20) << endl;
	Listack<long> f;
	f.push_back(0);
	f.push_back(1);
	for(int i=0; i<100; i++) {
		long a = f.pop();
		long b = f.pop();
		f.push_back(b);
		f.push_back(a+b);
	}
	cout << f.pop_back() << endl;

}

