#include<algorithm>
#include<functional>
#include<iostream>
#include<valarray>
using namespace std;
using namespace placeholders;
int plusa(int a, int b) { return a+b;}
int main()
{
	int a[10] = {2, 4, 2,5,6};
	int c[10] = {4, 5, 4,4,4};
	int d[10];
	//sort(a, a+10, less_equal<int>());
	transform(a, a+10,  c,d, &plusa);
	for(auto& b : d) cout << b << ' ';
	int x = 10, y = 1;
	swap(x, y);
	cout << endl << x << ' ' << y << endl;
	copy(a, a+3, d);
	for(auto& b : d) cout << b << ' ';

}
