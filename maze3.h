#pragma once
#include <vector>
#define WALL '#'
#define ROAD ' '
#define STEP '.'
#define SHORTCUT '>'
#define OUTOFBOUND 'B'

class Maze
{
public:
	Maze(int w, int h);
	Maze(const Maze& m);
	~Maze();
	bool show_maze() const;
	bool show_shortest() const;
	void best_way(int x, int y);
	void find_way(int x, int y);
	char operator()(int x, int y);

protected:
	

private:
	char** maze;
	static char** shortcut;
	static int shortest_steps;
	bool show(char** m) const;
	int get(int x, int y) const;
	void copy_maze(char** src, char**& dest);
	void alloc_maze(char**& m);
	void build_maze();
	int width, height, step = 0;
};
