#include <map>
#include <vector>
#include<algorithm>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

int main (int argc, char** argv)
{
	if(argc < 2) {
		cout << "usage : " << argv[0] << " filename" << endl;
		return 0;
	}
	ifstream file(argv[1]);
	map<string, int> word;
	string s;
	while((file >> s).good()) word[s]++;

	vector<pair<int, string>> v;
	for(auto& a : word) v.push_back({a.second, a.first});
	sort(v.begin(), v.end(), [](pair<int, string> a, pair<int, string> b)
			{return a.first > b.first;});
	for(auto& a : v) cout << a.first << " : " << a.second << endl;
}
