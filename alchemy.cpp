#include <iostream>
#include <fstream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

class Combination
{
public:
	Combination(int n, int r);
	virtual	~Combination() { delete [] ar;}
	int& operator[](unsigned i) {return ar[i];}
	bool next();
	int size() {return r;}

protected:
	int* ar;
	int n, r;
};

class nPr : public Combination
{
public:
	nPr(int n, int r);
	virtual ~nPr() {delete [] on;}
	bool next();

private:
	bool* on;
	void inc_ar(int i);
};



Combination::Combination(int n, int r)
{
	//if(n < 1 || r < 1) throw NRexception();
	ar = new int[r];
	this->n = n;
	this->r = r;
}

nPr::nPr(int n, int r) : Combination(n, r)
{
	on = new bool[n+2];
	for(int i=0; i<r; i++) {
		ar[i] = i + 1;
		on[i] = true;
	}
	ar[r-1] = 0;
}
	
bool nPr::next()
{	
	inc_ar(r-1);

	int i = r-1;
	while(ar[i] == n+1) {
		if(--i == -1) return false;
		inc_ar(i);
	}
	while(i < r-1) {
		ar[++i] = 0;
		inc_ar(i);
	}
	return true;
}

void nPr::inc_ar(int i)
{
	on[ar[i]] = false;
	while(on[++ar[i]]);
	if(ar[i] != n+1) on[ar[i]] = true;
}

vector<vector<int>> recipe;

class Flask
{
public:
	set<int> inFlask;
	int insert(int m) {
		inFlask.insert(m);
		return check_recipe();
	}
	void show() {
		for(auto& a : recipe) {
			for(auto& b : a) {
				cout << b << ' ';
			}
			cout << endl;
		}
		cout << endl;
	}
	void clear() { inFlask.clear(); }

private:
	int check_recipe() {
		int tmp[16] {};
		int j=0;
		for(int i=0; i<recipe.size(); i++) {
			bool ok = true;
			if(recipe[i][0] == 0) ok = false;
			else {
				for(int i2=1; i2<recipe[i].size(); i2++)
					if(inFlask.find(recipe[i][i2]) == inFlask.end()) ok = false;
			}
			if(ok) tmp[j++] = i;//
		} 
		//for(auto& a : tmp) cout << a << ' ';
		sort(tmp, tmp+j, [&](int a, int b) {
			if(recipe[a].size() == recipe[b].size()) {
				sort(recipe[a].begin()+1, recipe[a].end());
				sort(recipe[b].begin()+1, recipe[b].end());
				auto ait = recipe[a].rbegin();
				auto bit = recipe[b].rbegin();
				while(*ait == *bit) { ait++; bit++;	}
				return *ait > *bit;
			} else return (recipe[a].size() > recipe[b].size());
		});
		return tmp[0];
	}
	
};

int main() 
{
	int N, item;
	ifstream f("al.txt");
	f >> N;
	for(int cs=0; cs<N; cs++) {
		f >> item;
		vector<int> s;
		int ing;
		for(int i=0; i<item; i++) {
			f >> ing;
			int in;
			s.push_back(ing);
			for(int j=0; j<ing; j++) {
				f >> in;
				s.push_back(in);
			}
			recipe.push_back(s);
			s.clear();
		}
		Flask flask;
		for(int j=0; j<recipe.size(); j++) {
			int sz = recipe[j].size()-1;
			if(sz == 0) cout << '0';
			else {
				cout << sz << ' ';
				nPr p(sz, sz);
				bool synth = false;
				while(p.next() && !synth) {
					flask.clear();
					for(int i=0; i<sz; i++) {
						int boom = flask.insert(recipe[j][p[i]]);
						if(boom != 0) {
							if(boom == j) {
								for(int i=0; i<sz; i++)
									cout << recipe[j][p[i]] << ' ';
								synth = true;
							} 
							break;
						}
					}
				}
				if(!synth) cout << "IMPOSSIBLE";
			}
			cout << endl;
			flask.clear();
		}
		cout << endl;
		recipe.clear();
	}
}
