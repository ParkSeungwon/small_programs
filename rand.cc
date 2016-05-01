#include <random>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	default_random_engine dre;
	
	uniform_int_distribution<int> di(10, 20);
	for(int i=0; i<20; i++) cout << di(dre) << " " ;
	cout<< endl;

	uniform_real_distribution<double> dr(10, 20);
	for(int i=0; i<8; i++) cout << dr(dre) << " ";
	cout << endl;

	binomial_distribution<> bi;
	for(int i=0; i<20; i++) cout << bi(dre) << " ";
	cout << endl;

	vector<int> v {1, 2, 3,4,5,6,7,8,9};
	shuffle(v.begin(), v.end(), dre);
	for(int i=0; i < v.size(); i++) cout << v[i] << " ";
	cout << endl;
}
