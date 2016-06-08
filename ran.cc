#include<random>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

int main()
{
	vector<int> v;
	for(int i=0; i<101; i++) v.push_back(i);

	shuffle(v.begin(), v.end(), random_device());
	for(int i=0; i<31; i++) cout << v[i] << ' ';
}

	
