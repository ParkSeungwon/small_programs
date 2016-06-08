#include <iostream>
#include <set>
#include<cmath>
using namespace std;

int backward(int i)
{
	int ret = 0;
	for(int j=3; j>=0; i/=10) ret += (i%10) * pow(10, j--);
	return ret;
}

int main()
{
	set<int> v;
	for(int i=1000; i<10000; i++) v.insert(i - backward(i));
	cout << v.size() << endl;
	for(auto& a : v) cout << a << ' ';
}
		
