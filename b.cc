#include<fstream>
#include<string>
#include<iostream>
using namespace std;

string get_line(istream& i) {
	char c, prev;
	string s;
	while(i >> noskipws >> c) {
		prev = c;
		s += c;
		if(c == '\n'){ 
			s.back() = '\0';
			break;
		}
	}
	return s;
}

int main()
{
	ifstream f("a.cc");
	string s = get_line(f);
	cout << s;
	s = get_line(f);
	cout << s;
}
