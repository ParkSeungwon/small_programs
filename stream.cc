#include<sstream>
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;

struct Point {
	int x, y;
} p;

stringstream& operator>>(stringstream& ss, Point& p)
{
	ss >> p.x;
	ss >> p.y;
	return ss;
}

char buff[30];

int main(int c, char** v)
{
	stringstream ss;
	string s = ",def,,dfd,";
	ss << s;
	while(getline(ss, s, ',')) cout << s << endl;
}
