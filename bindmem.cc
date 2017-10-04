#include<iostream>
#include<functional>
using namespace std;

class A 
{
public:
	A() {
		f = bind(&A::on_click, this);
	}
	int n=0;
	function<void(void)> f;

protected:
	void on_click() {
		cout << this->n;
	}

};

int main()
{
	A a;
	a.f();
	a.n = 3;
	a.f();
	A b;
	b.f();

}
	
