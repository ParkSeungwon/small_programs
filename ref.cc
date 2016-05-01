#include <iostream>
using namespace std;

int& f(int &a)
{
	a++;
	return a;
}

class A
{
	public:
		A(int k) : i(k) {}
		A& operator=(A a) {
			i = a.i;
			return *this;
		}
		friend ostream& operator<<(ostream& os, const A& a) {
			os << a.i;
			return os;
		}//not member func
		int f(A a) {return a.k;}
		int i = 0;
	private:
		int k;
};

int main()
{
	int i=7;
	f(i);
	int& a = f(i) = f(i);
	cout << a << endl;
	A d(3), b(2), c(3);
	cout << (b=c=d) << endl;

}

