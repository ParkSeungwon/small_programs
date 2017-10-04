#include<iostream>
#include<random>
#include<vector>
using namespace std;

bool honest[100000] {};
bool told[100000] {};

uniform_int_distribution<> di(0, 3);
uniform_int_distribution<> diwho(0,99999);
random_device rd;

void tell_who(int n)
{
	honest[n] = true;
	vector<int> v;
	for(int i=0; i<di(rd); i++) v.push_back(diwho(rd));
	for(auto& a : v) {
		if(!told[a]) {
			told[a] = true;
			tell_who(a);
		}
	}
}

int main()
{
	tell_who(0);
	int k=0;
	for(int i=0; i<100000; i++) if(honest[i]) k++;
	cout << k;
}
