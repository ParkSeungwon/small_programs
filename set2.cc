#include <iostream>
using namespace std;

class Set
{
public:

	void Add(int i) {
		p[count] = i;
		count++;
	}
	friend ostream& operator<<(ostream& os, const Set& s) {
		os << "< ";
		for(int i=0; i<s.count; i++) os << s.p[i] << ' ';
		os << '>';
		return os;
	}
	Set operator+(Set& s) {
		Set r(*this);
		for(int i=0; i<s.count; i++) if(!find(s.p[i])) r.Add(s.p[i]);
		return r;
	}
	Set operator-(Set& s) {
		Set r;
		for(int i=0; i<count; i++) if(!s.find(p[i])) r.Add(p[i]);
		return r;
	}
	Set operator^(Set& s) {
		Set r;
		for(int i=0; i<count; i++) if(s.find(p[i])) r.Add(p[i]);
		return r;
	}

protected:
	int p[100];
	int count = 0;

private:
	bool find(int j) {
		for(int i=0; i<count; i++) if(j == p[i]) return true;
		return false;
	}

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
	
	C = A + B;
	D = (A - B) ^ C;
	E = A ^ B;
	cout << "집합 A : " << A << endl;
	cout << "집합 B : " << B << endl;
	cout << "집합 C : " << C << endl;
	cout << "집합 D : " << D << endl;
	cout << "집합 E : " << E << endl;
}
