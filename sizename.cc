#include <iostream>
using namespace std;
int main()
{
	const char *name[] = {"jsnl", "fjkslfal", "fjdslkjkf", "박승원", "df", "er", "우리는 사나이 진짜 사나이씩씩 하고 "};
	cout << sizeof(name) << ',' << sizeof(char*) << sizeof(int)<< endl;
	for(int i=0; name[i] !=NULL; i++) cout << name[i] << endl;
}
