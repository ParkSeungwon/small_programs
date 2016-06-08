#include<iostream>
#include<bitset>
#include<string>
using namespace std;

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	bitset<16>bs1 {s1};
	bitset<16>bs2 {s2};
	bs1 = bs1.to_ulong() * bs2.to_ulong();
	cout << bs1 << endl;
}
