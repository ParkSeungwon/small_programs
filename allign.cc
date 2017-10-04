#include<set>
#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
	set<int> A, B;
	A.insert(1);
	int n = atoi(argv[1]), i;
	for(i=1; A.find(n) == A.end(); i++) {
		for(auto& a : A) for(auto& b : A) B.insert(a + b);
		for(auto& c : B) {
			A.insert(c);
			cout << c << ' ';
		}
		cout << endl;
	}
	cout << i << endl;
}
