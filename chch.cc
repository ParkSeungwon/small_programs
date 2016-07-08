#include<iostream>
using namespace std;

int main()
{
	char ch[14];
	for(auto& a : ch) cin >> a;
	cout << "19" << ch[0] << ch[1] << '/' << ch[2] << ch[3] << '/' << ch[4];
	cout << ch[5] << ' ' << (ch[7] == '1' ? 'M' : 'F') << endl;
} 
