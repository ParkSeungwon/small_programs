#include <iostream>
#include <vector>
using namespace std;
class Arr
{
public:
	vector<vector<int>> v;
	vector<int> operator[](int x) {
		return v[x];
	}
};

int main()
{
	Arr a;
	a.v = {{{3,2,1},{5,6,7},{7,8,9}}};
	cout << a[2][2];
	
}
