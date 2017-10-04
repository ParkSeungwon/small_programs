#include<vector>
#include<iostream>
#include<random>
#include<algorithm>
#include<functional>
using namespace std;
using namespace std::placeholders;

void show(vector<int> v) 
{
	for(auto& a : v) cout << a;
	cout << endl;
}
class A
{
public:
	bool Is(int a, int b, bool bo) {
		return bo ? a<b : a>b;
	}
};

int main()
{
	A a;
	vector<int> v {1,2,3,4,5,6,7,2,3};
	sort(v.begin(), v.end(), bind(&A::Is, a, _1, _2, false));
	show(v);
	cout << getenv("HOME");
	cout << getenv("HTTP_COOKIE");

}
