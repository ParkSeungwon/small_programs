#include<fstream>
using namespace std;

int main()
{
	char ch[100];
	ifstream f1("memo1.txt");
	ofstream f2("memo2.txt");
	int i = 0;
	while(!(f1 >> noskipws >> ch[i++]).eof()) ;
	while(i>=0) f2 << ch[i--];
}
