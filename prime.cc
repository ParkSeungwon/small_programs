#include <vector>
#include <iostream>
using namespace std;

vector<unsigned int> div(long num)
{
	vector<unsigned int> prime, component;
	bool isPrime;

	for(unsigned int i=2; ;i++) {
		isPrime = true;
		for(auto& a : prime) {
			if(i % a == 0) {
				isPrime = false;
				break;
			}
		}
		if(isPrime) {
			prime.push_back(i);
			//cout << i << " ";
			while(num % i == 0) {
				component.push_back(i);
				num /= i;
			}
		}

		if(1 == num) return component;
	}
}

int main(int argc, char** argv)
{
	if(argc < 2) {
		cout << "usage : " << argv[0] << " [소인수분해할 수]" << endl;
		return 0;
	}
	long n = atoi(argv[1]);
	for(auto& a : div(n)) cout << a << "*";
	cout << " = " << n << endl;
}
