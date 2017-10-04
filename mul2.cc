#include<iostream>
#include<deque>
using namespace std;

void mul2(deque<int>& s)
{
	int n;
	for(auto& a : s) a *= 2;
	for(int i=s.size()-1; i > 0; i--) {
		n = s[i];
		s[i] = n % 10;
		s[i-1] += n / 10;
	}
	if(s[0] >= 10) {
		n = s[0];
		s[0] = n % 10;
		s.push_front(n / 10);
	}
}

int main(int c, char** v)
{
	if(c < 2) {
		cout << "usage : " << v[0] << " [n승" << endl;
		return 0;
	}
	deque<int> dq;
	dq.push_back(1);
	for(int i=0; i<stoi(v[1]); i++) mul2(dq);
	cout << "size = " << dq.size() << endl;
	if(dq.size() > 1002) cout << dq[dq.size() - 1002] << ' ' << dq[dq.size() - 1001] << endl;

	for(auto& a : dq) cout << a;
	cout << endl;
}


