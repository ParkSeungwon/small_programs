#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include "maze.h"
using namespace std;

int Maze::count = 10000;
vector<vector<int>> Maze::road = {};

void Maze::show_maze(const vector<vector<int>>& v) const
{
	cout << "Map : s.start e.end 0.wall 1.road 2.can_go 3.shortest_road" << endl;
	cout << "width = " << width << " height = " << height << endl;
	for(int y=0; y<height; y++) {
		for(int x=0; x<width; x++) {
			if(x == 0  && y == 0) cout << 's';
			else if(x == width-1 && y == height-1) cout << 'e';
			else cout << v[y][x];
		}
		cout << endl;
	}
}

bool Maze::show() const
{
	show_maze(maze);
	return maze[height-1][width-1] == 2;
}

int Maze::show_road() const
{
	show_maze(road);
	return count;
}

void Maze::find_way(int x, int y) {
	maze[y][x] = 2;
	if(get(x, y-1) == 1) find_way(x, y-1);
	if(get(x, y+1) == 1) find_way(x, y+1);
	if(get(x-1, y) == 1) find_way(x-1, y);
	if(get(x+1, y) == 1) find_way(x+1, y);
}

int Maze::get(int x, int y)
{
	if(x < 0 || x >= width) return -1;
	if(y < 0 || y >= height) return -1;
	return maze[y][x];
}

void Maze::best_way(int x, int y)
{
	maze[y][x] = 3;
	if(width-1 == x && height-1 == y) {
		if(c < count) {
			count = c;
			road = maze;
			if(c == width + height - 2) {
				show_road();
				cout << "took " << c << "steps" << endl;
				exit(0);
			}
		}
		return;
	}
	if(c >= count) return;
	if(get(x, y-1)==2) {
		if(get(x+1, y-1) == 3) return;
		if(get(x-1, y-1) == 3) return;
		if(get(x, y-2) == 3) return;
		Maze m(*this);
		m.c++;
		m.best_way(x, y-1);
	}
	if(get(x, y+1)==2) {
		if(get(x+1, y+1) == 3) return;
		if(get(x-1, y+1) == 3) return;
		if(get(x, y+2) == 3) return;
		Maze m(*this);
		m.c++;
		m.best_way(x, y+1);
	}
	if(get(x-1, y) == 2) {
		if(get(x-1, y+1) == 3) return;
		if(get(x-1, y-1) == 3) return;
		if(get(x-2, y) == 3) return;
		Maze m(*this);
		m.c++;
		m.best_way(x-1, y);
	}
	if(get(x+1, y) == 2) {
		if(get(x+1, y-1) == 3) return;
		if(get(x+1, y+1) == 3) return;
		if(get(x+2, y) == 3) return;
		Maze m(*this);
		m.c++;
		m.best_way(x+1, y);
	}
}

void Maze::build_maze(int w, int h)
{
	width = w; height = h;
	uniform_real_distribution<> nd(0,10);
	knuth_b e(chrono::system_clock::now().time_since_epoch().count());
	vector<int> v;
	maze.clear();
	for(int y=0; y<h; y++) {
		for(int x=0; x<w; x++) {
			if(nd(e) > 4) v.push_back(1);
			else v.push_back(0);
		}
		maze.push_back(v);
		v.clear();
	}
	maze[0][0] = 1;
	maze[h-1][w-1] = 1;
	c = 0; count = 10000;
}

int main(int argc, char** argv)
{
	if(argc < 3) {
		cout << "usage : " << argv[0] << " width height" << endl;
		return 0;
	}
	int w=atoi(argv[1]);
	int h=atoi(argv[2]);

	Maze maze;
	while(true) {
		maze.build_maze(w, h);
		maze.show();
		maze.find_way(0,0);
		if(maze.show()) {
			maze.best_way(0,0);
			cout << "took " << maze.show_road() << " steps" << endl;
			break;
		} else {
			cout << "cannot find the way " << endl << endl;
		}
	}
}
