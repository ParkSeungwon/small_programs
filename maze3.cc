#include <iostream>
#include <random>
#include <chrono>
#include "maze3.h"
using namespace std;

int Maze::shortest_steps = 10000;
char** Maze::shortcut = nullptr;

Maze::Maze(int w, int h)
{
	width = w; height = h;
	alloc_maze(maze);
	if(shortcut == nullptr) alloc_maze(shortcut);
	build_maze();
}

Maze::Maze(const Maze& m)
{
	height = m.height; 
	width = m.width;
	step = m.step;
	alloc_maze(maze);
	copy_maze(m.maze, maze);
}

void Maze::alloc_maze(char**& maze)
{
	maze = new char*[height];
	for(int i=0; i<height; i++) maze[i] = new char[width];
}

void Maze::copy_maze(char** src, char**& dest)
{
	for(int y=0; y<height; y++) {
		for(int x=0; x<width; x++) {
			dest[y][x] = src[y][x];
		}
	}
}

Maze::~Maze()
{
	for(int i=0; i<height; i++) delete [] maze[i];
	delete [] maze;
}

void Maze::build_maze()
{
	uniform_real_distribution<> nd(0,10);
	knuth_b e(chrono::system_clock::now().time_since_epoch().count());
	for(int y=0; y<height; y++) {
		for(int x=0; x<width; x++) {
			if(nd(e) > 4) maze[y][x] = ROAD;
			else maze[y][x] = WALL;
		}
	}
	maze[0][0] = ROAD;
	maze[height-1][width-1] = ROAD;
	shortest_steps = 10000;
}

char Maze::operator()(int x, int y)
{
	if(x<0 || x>=width) return OUTOFBOUND;
	if(y<0 || y>=height) return OUTOFBOUND;
	return maze[y][x];
}

bool Maze::show_maze() const
{
	return show(maze);
}

bool Maze::show_shortest() const
{
	return show(shortcut);
}

bool Maze::show(char** maze) const
{
	cout << "width = " << width << " height = " << height << endl;
	cout << WALL << ROAD;
	for(int i=0; i<width; i++) cout << WALL;
	cout << endl;
	for(int y=0; y<height; y++) {
		cout << WALL;
		for(int x=0; x<width; x++) {
			cout << maze[y][x];
		}
		cout << WALL << endl;
	}
	for(int i=0; i<width; i++) cout << WALL; 
	cout << ROAD << WALL << endl;
	return STEP == maze[height-1][width-1];
}

void Maze::find_way(int x, int y) {
	maze[y][x] = STEP;
	if(get(x, y-1) == ROAD) find_way(x, y-1);
	if(get(x, y+1) == ROAD) find_way(x, y+1);
	if(get(x-1, y) == ROAD) find_way(x-1, y);
	if(get(x+1, y) == ROAD) find_way(x+1, y);
}

int Maze::get(int x, int y) const
{
	if(x < 0 || x >= width) return OUTOFBOUND;
	if(y < 0 || y >= height) return OUTOFBOUND;
	return maze[y][x];
}

void Maze::best_way(int x, int y)
{
	maze[y][x] = SHORTCUT;
	if(step >= shortest_steps) return;
	if(width-1 == x && height-1 == y) {
		if(step < shortest_steps) {
			shortest_steps = step;
			copy_maze(maze, shortcut);
			if(step == width + height - 2) {
				show_shortest();
				cout << "took " << step << "steps" << endl;
				exit(0);
			}
		}
		return;
	}
	if(get(x, y-1) == 2) {
		if(get(x+1, y-1) == SHORTCUT) return;
		if(get(x-1, y-1) == SHORTCUT) return;
		if(get(x, y-2) == SHORTCUT) return;
		Maze m(*this);
		m.step++;
		m.best_way(x, y-1);
	}
	if(get(x, y+1) == 2) {
		if(get(x+1, y+1) == SHORTCUT) return;
		if(get(x-1, y+1) == SHORTCUT) return;
		if(get(x, y+2) == SHORTCUT) return;
		Maze m(*this);
		m.step++;
		m.best_way(x, y+1);
	}
	if(get(x-1, y) == 2) {
		if(get(x-1, y+1) == SHORTCUT) return;
		if(get(x-1, y-1) == SHORTCUT) return;
		if(get(x-2, y) == SHORTCUT) return;
		Maze m(*this);
		m.step++;
		m.best_way(x-1, y);
	}
	if(get(x+1, y) == 2) {
		if(get(x+1, y-1) == SHORTCUT) return ;
		if(get(x+1, y+1) == SHORTCUT) return;
		if(get(x+2, y) == SHORTCUT) return;
		Maze m(*this);
		m.step++;
		m.best_way(x+1, y);
	}
}


int main(int argc, char** argv)
{
	if(argc < 3) {
		cout << "usage : " << argv[0] << " width height" << endl;
		return 0;
	}
	int w = atoi(argv[1]);
	int h = atoi(argv[2]);
	Maze m(w, h);
	m.show_maze();
	m.find_way(0, 0);
	if(m.show_maze()) m.best_way(0, 0);
	m.show_shortest();
	
}

