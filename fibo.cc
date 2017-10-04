#include <iostream>
#include <vector>
using namespace std;

class FiboSum
{
public:
	FiboSum(int n) {
		for(int i=2, j=0; j<=n; i++) v.push_back(j = fibo(i));
		sum = n;
		find_plus(v.begin());

	}
	void show() { 
		for(auto& a : r) {
			for(auto& b : a) cout << b << " + " ;
			cout << " = " << sum << endl;
		}
	}
	void purge() {r.clear();}
	
private:
	vector<int> tmp;
	static vector<int> v;
	static vector<vector<int>> r;
	int sum, accum=0;
	
	int fibo(int n) {
		if(n < 3) return 1;
		else return fibo(n-1) + fibo(n-2);
	}
	
	void find_plus(vector<int>::iterator it)
	{
		for(; it != v.end(); it++) {
			if(accum + *it < sum) {
				FiboSum f{*this};
				f.tmp.push_back(*it);
				f.accum += *it;
				f.find_plus(it+1);
			} else if(accum + *it == sum) {
				tmp.push_back(*it);
				accum += *it;
				r.push_back(tmp);
			} else break;
		}
	}
};

vector<int> FiboSum::v = {};
vector<vector<int>> FiboSum::r = {};

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
	
	{
	int f[3] ={1,2,3};
	int sum = 0;
		
	for(int i=0; f[i%3] < 4000000; i++) {
		if(!(f[i%3] % 2)) sum += f[i%3];
		f[i%3] = f[(i+1)%3] + f[(i+2)%3];
	}
	cout << sum << endl;
	}
}
	
