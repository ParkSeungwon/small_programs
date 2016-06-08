#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	signed char c = 's'+1;
	cout << sizeof(short)<< endl;
	cout << "우리는 사나 二c" << endl;
	cout.width(6);
	cout << 23 << endl;
	cout << 34 << setfill('^') << setw(6) << 23 << endl;
	cout << dec << +c << endl;
}
