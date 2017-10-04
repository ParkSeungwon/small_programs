#include<fstream>
#include<map>
#include<string>
#include<iostream>
using namespace std;

int main() {
	ifstream f("test.txt");
	multimap<string, string> m;
	string s1, s2;
	while(getline(f, s1, ' ')) {
		getline(f, s2);
		m.insert({s1, s2});
	}
	for(auto& a : m) cout << a.first << ':' << a.second << endl;

	getline(cin, s1);
	for(auto& a : m) if(a.first == s1) cout << a.second << endl;
}
