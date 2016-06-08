#include <iostream>
using namespace std;

int main()
{
	char c = 'a';
	for(unsigned char i=0x21; i<0x7f; i++)
		cout << hex << showbase << +i << ':' << i << ' ';
}
