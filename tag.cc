#include<sstream>
#include<string>
#include<fstream>
#include<iostream>
#include<iomanip>
using namespace std;

int main(int c, char** v)
{
	ifstream f(v[1]);
	char ch, TAG;
	string addr1, addr2, len;
	string s;
	f >> TAG >> s >> setw(6) >> addr1 >> setw(6) >> addr2;
	cout << "TAG : " << TAG << endl;
	cout << "PROGNAME : " << s << endl;
	cout << "ADDR1 : " << setw(6) << setfill('0') << hex << stoi(addr1, nullptr, 16) << endl;
	cout << "ADDR2 : " << setw(6) << setfill('0') << hex << stoi(addr2, nullptr, 16) << endl << endl;

	f >> TAG >> setw(6) >> addr1 >> setw(2) >> hex >> len >> s;
	cout << "TAG : " << TAG << endl;
	cout << "ADDR : " << setw(6) << setfill('0') << hex << stoi(addr1, nullptr, 16) << endl;
	cout << "LENGTH : " << len << endl;
	cout << "CODES : " << s << endl << endl;

	f >> TAG >> s;
	cout << "TAG : " << TAG << endl;
	cout << "OTHERS : " << s << endl;
}

