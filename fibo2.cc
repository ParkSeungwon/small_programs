#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

class FiboSum
{
public:
	FiboSum(int n) {
		for(int i=2, j=0; j<=n; i++) v.insert(j = fibo(i));
		find_plus(n);
	}
	void show() { 
		for(auto& a : r) {
			for(auto& b : a) cout << b << " + " ;
			cout << " = " << accumulate(a.begin(), a.end(), 0) << endl;
		}
	}
	void purge() {r = {};}
	
private:
	set<int> tmp;
	static set<int> v;
	static set<set<int>> r;
	
	int fibo(int n) {
		if(n < 3) return 1;
		else return fibo(n-1) + fibo(n-2);
	}
	
	void find_plus(int sum)
	{
		int accum = accumulate(tmp.begin(), tmp.end(), 0);
		for(auto& a : v) {
			if(tmp.find(a) != tmp.end()) break;//to remove order diff
			if( accum + a == sum) {
				tmp.insert(a);
				r.insert(tmp);
			} else if(accum < sum) {
				FiboSum f{*this};
				f.tmp.insert(a);
				f.find_plus(sum);
			}
		}
	}
};

set<int> FiboSum::v = {};
set<set<int>> FiboSum::r = {};

int main(int argc, char** argv)
{
	if(argc < 2) {
		cout << "usage : " << argv[0] << " [피보나치할 수]" << endl;
		return 0;
	}
	int i = atoi(argv[1]);
	FiboSum f {i};
	f.show();
	f.purge();
}
	
