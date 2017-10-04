#include<iostream>
#include<regex>
#include<string>
using namespace std;

int main() 
{
	regex e1(R"lit(\w{6,12}@\w+\.\w+)lit");
	regex e2("(abc){3}");
	string s = "zezeon@gmail.com";
	cout << regex_match(s, e1) << endl;
	string s2 = "abcabc";
	cout << regex_match(s2, e2) << endl;
}
