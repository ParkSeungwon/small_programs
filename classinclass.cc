class B {
	public:
		int i;
};

class A {
	public:
		class B b;
};

int main() 
{
	A a[10];
	a[2].b.i = 3;
}


