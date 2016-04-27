#include <iostream>
#include <bitset>
using namespace std;

template <typename T>
void bitint(T i)
{
	for(int j = sizeof(T) * 8 - 1; j >= 0; j--) cout << ( (i & (1 << j)) >> j );
	cout << endl;
}

template <typename T>
void bitint3(T i)
{
	cout << bitset<sizeof(T)*8>(i) << endl;
}


void bitint2(int x)
{
	int mask = 1;
	while (mask <= x) { 
      mask <<= 1; 
   } 
   while (mask >>= 1) { 
      printf("%d", (x & mask) ? 1 : 0); 
   } 
   cout << endl;
}

int main()
{
	union {
		float f;
		int i;
		char c[4];
	} u;
	cin >> u.i;
	bitint2(u.i);
	cout << bitset<16>(0xff) << endl;
	for(auto& a : u.c) bitint(a);
}

