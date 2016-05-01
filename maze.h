#pragma once
#include <vector>

class Maze
{
public:
	void build_maze(int w, int h);
	bool show() const;
	int show_road() const;
	void find_way(int x, int y);
	void best_way(int x, int y);

private:
	static int count;
	int get(int x, int y);
	void show_maze(const std::vector<std::vector<int>>& v) const;
	std::vector<std::vector<int>> maze;
	static std::vector<std::vector<int>> road;
	int width, height, c;
};
