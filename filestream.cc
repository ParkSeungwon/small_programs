#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
	ifstream f {argv[1]};
	ofstream o {"aa.txt", fstream::app};
	string s;
	while(!(f>>s).eof()) {
		int i;
		while((i = s.find(',')) != -1) s.erase(i,1);//delete all ,
		cout << s;
		o << s << endl;
	}
}
