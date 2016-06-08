#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

int main()
{
	int ar[1] = {1};//,3,4,2,5,6,7,8,2,1};
	sort(ar, ar+1, [](int a, int b) { return a>b; });
	cout << (*find(ar, ar+10, 4)=3) << endl;
	for(auto& a : ar) cout << a << ' ';
	vector<vector<int>> v;
	vector<int> v2;
	v.push_back(v2);
	for(auto& a : v) for(auto& b : a) cout << b << endl;
}
