#include "boolarray.h"
using namespace std;

bool BoolArray::operator[](int x)
{
	if(x<0 || x>= bs.size()) throw 1;
	else return bs[x];
}
int main(){}
