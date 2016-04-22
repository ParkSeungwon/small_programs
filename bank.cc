#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int money = 1000000;
	int year;
	cin >> year;
	money = money * pow(1 + 0.045, year);
	cout << "money after " << year << " is " << money << endl;
}
