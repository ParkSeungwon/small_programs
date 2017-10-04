#include<iostream>
#include<string>
#include<set>
using namespace std;

set<string> clause(int n)
{
	set<string> r;
	if(n == 1) r.insert("()");
	else { 
		for(auto& a : clause(n-1)) {
			r.insert("()" + a);
			r.insert('(' + a + ')');
			r.insert(a + "()");
		}
	}
	return r;
}
		 
int main(int c, char** v)
{
	if(c < 2) cout << "usage : " << v[0] << " [number of clause]" << endl;
	else for(auto& a : clause(atoi(v[1]))) cout << a << endl;
}
