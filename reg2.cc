#include<regex>
#include<string>
#include<iostream>
using namespace std;

int main(int ac, char** av) 
{
	string s = "<p id='fd'>뮤라나</p><p></p>";
	regex e{R"(<([^\s>]+)(.*?)>(.*?)</\1>)"};
	R"(<([\s>]+).*?/>)";
	smatch m;
	while(regex_search(s, m, e)) {
		for(auto& a : m) cout << a << endl;
		s = m.suffix().str();
	}
}

