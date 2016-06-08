#include <iostream>
#include<vector>
#include<algorithm>
#include <fstream>
using namespace std;

struct Path
{
	int a, b;
	int v;
	bool c;
};

class Tree
{
public:
	vector<Path> paths;
	int cross[101];
	int N, path, minN, minSum;
	void del_path(int i) {
		paths[i].c = false;
		cross[paths[i].a]--;
		cross[paths[i].b]--;
	}
	void sortPath() {
		sort(paths.begin(), paths.end(), [](Path a, Path b){return a.v > b.v;});
	}
	bool check_cross() {
		for(int i=1; i<=N; i++) if(cross[i] == 0) return false;
		return true;
	}
	void show() {
		cout << N << ' ' << path << endl;
		for(int i=1; i<=N; i++) cout << cross[i] << ' ';
		cout << endl;
		for(auto& a : paths) if(a.c) cout << a.a << ' ' << a.b << ' ' << a.v << endl;
		cout << endl;
	}

};

int main()
{
	ifstream f("input.txt");
	int c, N, path;
	f >> c;
	Tree* tree = new Tree[c];
	
	for(int i=0; i<c; i++) {
		f >> tree[i].N >> tree[i].path;
		Path p;
		for(int j=0; j<tree[i].path; j++) {
			f >> p.a >> p.b >> p.v;
			p.c = true;//draw, delete
			tree[i].cross[p.a]++;
			tree[i].cross[p.b]++;
			tree[i].paths.push_back(p);
		}
		tree[i].sortPath();
		tree[i].show();
		for(int j=0; tree[i].check_cross(); j++) tree[i].del_path(j);
		tree[i].show();
	}
	f.close();
	delete [] tree;

//	for(int i=0; i < 1<<path; i++) {
//		for(int j=0; j<path; j++) p[i][3] = i & 1<<j;

//	}


}

	
