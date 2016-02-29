#include <random>
#include <map>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

template <typename Distr, typename Eng>
void distr(Distr d, Eng e, const string& name)
{
	cout << name << ":" << endl;
	cout << " - min() : " << d.min() << endl;
	cout << " - max() : " << d.max() << endl;
	cout << " - values : " << d(e) << ' ' << d(e) << ' ' << d(e) << ' ' << d(e) <<endl;
	
	map<long long, int> valuecounter;
	for(int i=0; i<200000; i++) valuecounter[d(e)]++;
	
	cout << "======" << endl;
	for(auto elem : valuecounter) 
		cout << setw(3) << elem.first << ": " << elem.second << endl;
	cout << "======" << endl << endl;
}

int main() 
{
	knuth_b e;
	uniform_real_distribution<> ud(0, 10);
	distr(ud, e, "uniform_real_distribution");
	normal_distribution<> nd;
	distr(nd, e, "normal_distribution");
	exponential_distribution<> ed;
	distr(ed, e, "exponential_distribution");
	gamma_distribution<> gd;
	distr(gd, e, "gamma_distribution");
	//bernoulli_distribution<> bd;
	//distr(bd, e, "bernoulli_distribution");
	binomial_distribution<> bi;
	distr(bi, e, "binomial_distribution");
	geometric_distribution<> geo;
	distr(geo, e, "geometric_distribution");
	poisson_distribution<> po;
	distr(po, e, "poisson_distribution");
}
