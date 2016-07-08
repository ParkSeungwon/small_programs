#include<iostream>
#include<map>
using namespace std;

bool isPrime(int n) {
	for(int i=2; i <= n/2; i++) if(n % i == 0) return false;
	return true;
}

int p(int n) {
	for(int i=2, count=0; ; i++) {
		if(isPrime(i)) count++;
		if(count == n) return i;
	}
}

int k(int n) {
	return n == 1 ? 1 : p(n) - k(n-1);
}
/*
 *kn=pn-kn-1=pn-(p(n-1)-k(n-1)=pn-pn-1+pn-2-.....-p1+k1
 *
 *
 * */

int main()
{
	map<int, int> m;
	for(int i=1, j; i<1000; i++) {
		j = k(i);
		m[j]++;
		cout << j << ' ' << flush;
	}
	for(auto& a : m) if(a.second > 1) cout << a.first;
}
