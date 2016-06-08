#include<map>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

int main()
{
	vector<int> v {1,1,2,2,3, 1,3,2,1,2, 1,3,2};
	map<int, int> m;
	for(auto& a : v) m[a]++;
	for(auto& a : m) {
		if(a.second != 5) {
			auto it = remove(v.begin(), v.end(), a.first);
			v.erase(it, v.end());
		}
	}
	m.clear();
	for(int i=0; i<v.size(); i++) m[v[i]] += i+1;
	for(auto& a : m) cout << a.first << ' ' << a.second << endl;
}
