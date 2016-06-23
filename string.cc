#include<string>
#include<iostream>
using namespace std;

int main()
{
	string s = "start the game";
	for(size_t pos  = 0; pos != string::npos;){
		pos = s.find(' ', pos);
		s[pos] = '\n';
		cout << pos << " = position" << endl;
		//cout << s << endl;
	}
	cout << s << endl;
}
