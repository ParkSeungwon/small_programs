#include <iostream>
#include <set>
using namespace std;

class Set
{
public:
	Set() {}
	void Add(int i) {
		v.insert(i);
	}
	friend ostream& operator<<(ostream& os, const Set& s) {
		os << "< ";
		for(auto& a : s.v) os << a << ' ';
		os << '>';
		return os;
	}
	Set operator+(const Set& s) {
		Set r(*this);
		for(auto& a : s.v) r.v.insert(a);
		return r;
	}
	Set operator-(const Set& s) {
		Set r(*this);
		for(auto& a : s.v) r.v.erase(a);
		return r;
	}
	Set operator^(const Set& s) {
		Set r;
		for(auto& a : s.v) if(v.find(a) != v.end()) r.v.insert(a);
		return r;
	}

protected:
	set<int> v;
};

int main()
{
	Set A, B, C, D, E;
	A.Add(1);
	A.Add(2);
	A.Add(3);
	A.Add(4);
	A.Add(5);
	B.Add(4);
	B.Add(5);
	B.Add(6);
	B.Add(7);
	B.Add(8);
	B.Add(10);
	B.Add(9);
	
	C = A + B + C;
	C = A + B + C;
	D = A - B;
	E = A ^ B;
	cout << "집합 A : " << A << B <<  endl;
	cout << "집합 B : " << B << endl;
	cout << "집합 C : " << C << endl;
	cout << "집합 D : " << D << endl;
	cout << "집합 E : " << E << endl;
	//cout << s << endl;
}
