#include <iostream>
#include <string>
using namespace std;

template <typename T>
T f(T t)
{
	string s = "test";
	cout << t(s);
	return t;
}



class Server
{
public:
	template <typename T> void start(T t) {
		string s = "test";
		cout << t(s);
	}
};

int main()
{
	auto f = [](string s) {
		string str = "[from server] ";
		str += s + " : " + to_string(s.size());
		return str;
	};

	Server sv;
	sv.start(f);
}

