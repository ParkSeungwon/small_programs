#include<vector>
#include<iostream>
#include<random>
#include<algorithm>
using namespace std;
void show(vector<int> v) 
{
	for(auto& a : v) cout << a;
	cout << endl;
}

bool Is(int a) {
	return a<=2;
}

int main()
{
	vector<int> v {1,2,3,4,5,6,7,2,3};
	sort(v.begin(), v.end());
	show(v);
	auto it = remove_if(v.begin(), v.begin()+5, Is);
	show(v);
	v.erase(it, v.begin()+5);
	show(v);
	it = find(v.begin(), v.end(), 4);
	v.erase(it);
	show(v);
	sort(v.begin(), v.end(), [](int a, int b){ return a%2 > b%2;});
	show(v);

	random_device rd;
	shuffle(v.begin(), v.end(), rd);
	show(v);
}
