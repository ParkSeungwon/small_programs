#include <chrono>
#include <ctime>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
using namespace std::chrono;

int main () 
{
//	seconds sec(1);
//	hours hr(1);
//	milliseconds ms(1);
//	cout << (hr + sec).count() << endl;
	auto now = system_clock::now();
	auto tp = system_clock::to_time_t(now);
	string t = ctime(&tp);
	unordered_map<string, string> months {
		{"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"}, 
		{"May", "05"}, {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"}, 
		{"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}
	};

	string s = t.substr(20, 4) + "-" + months[t.substr(4, 3)] + "-";
	if(t[8] == ' ') s += '0';
	else s += t[8];
	s += t.substr(9, 10);
	s.erase(10);
	s += ".sql";
	cout << s << endl;
}

