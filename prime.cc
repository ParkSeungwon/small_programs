#include <vector>
#include <iostream>
using namespace std;

vector<unsigned int> div(int num)
{
	vector<unsigned int> prime, component;
	bool isPrime;

	for(unsigned int i=2; ;i++) {
		isPrime = true;
		for(auto& a : prime) {
			if(i % a == 0) isPrime = false;
			if(num % a == 0) {
				component.push_back(a);
				num /= a;
			}
		}
		if(isPrime) {
			prime.push_back(i);
			cout << "prime " << i << endl;
		}

		if(1 == num) return component;
	}
}

int main()
{
	int n;
	cout << "number ? ";
	cin >> n;
	for(auto& a : div(n)) cout << a << "*";
	cout << " = " << n << endl;
}
