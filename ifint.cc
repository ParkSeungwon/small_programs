#include<iostream>
#include<string>
using namespace std;

template<typename T> int f(T b = 3, T a = 0) {
	cout << b << endl;
	cout << a << endl;
}
int main() {
	f<int>();
}
