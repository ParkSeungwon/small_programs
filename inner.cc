#include<numeric>
#include<iostream>
#include<tuple>
#include<regex>
using namespace std;

int main()
{
	int a[] = {2, 4, 5, 6, 9};
	int b[] = {3, 5, 1, 9, 7};

	cout << inner_product(a, a + 5, b, 0) << endl;
	cout << accumulate(a, a+5, 0) << endl;

	auto t = make_tuple(3, 4.8, 'c', "the");
	float f;
	char c;
	tie(ignore, f, c, ignore) = t;
	cout << f << ' ' << c << ' ' << endl;
	cout << get<0>(t) << endl;

	regex r(R"foo(\w+\.\w+)foo");
	cout << "enter : ";
	string s;
	cin >> s;
	cout << regex_match(s.begin(), s.end(), r);
}
