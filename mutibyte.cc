#include<string>
#include<iostream>
using namespace std;
int m(char c) {
	int r=1;
	if(c & 1<<7) for(int i=6; c & 1<<i && i>3; i--) r++;
	cout << r;
	return r;
}

int main()
{

	string s = "한계령";
	string vert;
	for(auto it = s.begin(); it != s.end();) {
		int n = m(*it);
		for(int i=0; i<n; i++, it++)  vert += *it;
		vert += '\n';
	}
	vert.pop_back();
	cout << vert << endl;
}
/*
	string vert;
	for(auto it = s.begin(); it != s.end(); it++) {
		vert += *it;
		int j = 0;
		for(int i=7; *it & 1<<i && i>0; i--) j++;
		for(int i=1; i<j; i++) {
			it++;
			vert += *it;
		}

		vert += '\n';
	}

	cout << vert << endl;
}*/
