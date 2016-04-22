#include <iostream>
using namespace std;

template <typename T>
void bitint(T i)
{
	for(int j = sizeof(T) * 8 - 1; j >= 0; j--) cout << ( (i & (1 << j)) >> j );
	cout << endl;
}

int main()
{
	union {
		float f;
		int i;
		char c[4];
	} u;
	cin >> u.f;
	bitint(u.i);
	for(auto& a : u.c) bitint(a);
}

