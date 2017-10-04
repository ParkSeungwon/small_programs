#include<cstdlib>
#include<iostream>
using namespace std;

int main() {
	const char* user = getenv("USER");
	string s;
	cout << "Password : ";
	system("stty -echo");
	cin >> s;
	system("stty echo");
	cout << user;

}
