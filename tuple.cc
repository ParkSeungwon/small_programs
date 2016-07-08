#include<tuple>
#include<iostream>
using namespace std;

int main()
{
	auto t = make_tuple(2, 3.14, "dfsf");
	int i; float f; 
	tie(i, f, ignore) = t;
	cout << get<0>(t) << ' ' << get<1>(t) << ' ' << get<2>(t) << endl;
	cout << i << ' ' << f << endl;
}

