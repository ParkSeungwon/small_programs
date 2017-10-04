#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

template <typename T>
vector<T> operator-(const vector<T>& l, const vector<T>& r) {
	vector<T> ret;
	for(auto& a : l) if(find(r.begin(), r.end(), a) == r.end()) ret.push_back(a);
	return ret;
}

template <typename T>
vector<T> operator&(const vector<T>& l, const vector<T>& r) {
	vector<T> ret;
	for(auto& a : l) if(find(r.begin(), r.end(), a) != r.end()) ret.push_back(a);
	return ret;
}

class Rectangle
{
public:
	Rectangle(int x1, int y1, int x2, int y2) {
		for(int x=x1; x<x2; x++) for(int y=y1; y<y2; y++) cubes.push_back({x, y});
	}
	Rectangle() {}
	friend Rectangle operator&(Rectangle& r1, Rectangle& r2) {
		Rectangle r;
		r.cubes = r1.cubes & r2.cubes;
		if(r1.cubes != r.cubes) r1.cubes = r1.cubes - r.cubes;
		else return Rectangle();
		if(r2.cubes != r.cubes) r2.cubes = r2.cubes - r.cubes;
		else return Rectangle();
		return r;
	}
	vector<Rectangle> divide() {
		vector<Rectangle> v;
		Rectangle r;
		while(!cubes.empty()) {
			next(cubes[0]);
			cubes = cubes - son;
			r.cubes = move(son);
			v.push_back(move(r));
		}
		return v;
	}
	int size() {return cubes.size();}
	bool empty() {return cubes.empty();}

protected:
	vector<pair<int, int>> cubes;//width 1, height 1인 정사각형의 집합으로 이해.

private:
	vector<pair<int, int>> son;
	void next(pair<int, int> cube) {
		son.push_back(cube);
		int x = cube.first; int y = cube.second;
		if(find(cubes.begin(), cubes.end(), pair<int,int>{x+1, y}) != cubes.end() && find(son.begin(), son.end(), pair<int, int>{x+1,y}) == son.end()) next({x+1, y});
		if(find(cubes.begin(), cubes.end(), pair<int,int>{x-1, y}) != cubes.end() && find(son.begin(), son.end(), pair<int, int>{x-1,y}) == son.end()) next({x-1, y});
		if(find(cubes.begin(), cubes.end(), pair<int,int>{x, y+1}) != cubes.end() && find(son.begin(), son.end(), pair<int, int>{x,y+1}) == son.end()) next({x, y+1});
		if(find(cubes.begin(), cubes.end(), pair<int,int>{x, y-1}) != cubes.end() && find(son.begin(), son.end(), pair<int, int>{x,y-1}) == son.end()) next({x, y-1});
	}
};

int main(int c, char** argv)
{
	if(c < 2) return 0;
	ifstream f(argv[1]);
	int cnt;
	vector<Rectangle> v, vr;
	int x1, y1, x2, y2;
	f >> cnt >> cnt;
	f >> x1 >> y1 >> x2 >> y2;
	v.push_back(Rectangle(x1, y1, x2, y2));
	for(int i=1; i<cnt; i++) {
		f >> x1 >> y1 >> x2 >> y2;
		Rectangle r(x1, y1, x2, y2);
		for(auto& a : v) {
			auto ra = r & a;
			for(auto& b : a.divide()) vr.push_back(b);
			for(auto& b : ra.divide()) vr.push_back(b);
		}
		for(auto& b : r.divide()) vr.push_back(b);
		v = move(vr);
	}
	cout << v.size() << endl;
	for(auto& a : v) cout << a.size() << ' ';
}

