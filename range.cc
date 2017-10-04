#include<vector>
#include<iostream>
using namespace std;

vector<int> range(int n) {
	vector<int> v;
	for(int i=0; i<n; i++) v.push_back(i);
	return v;
}

int main()
{
	for(auto& a : range(10)) cout << a << ' ';
}
