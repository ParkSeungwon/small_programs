#include <iostream> 
#include <vector> 
#include <random> 
using namespace std; 
struct Maze 
{ 
   Maze(vector<vector<int>> v); 
   static int count; 
   static vector<vector<int>> road; 
   void find_way(int x, int y); 
   int get(int x, int y) const;
   void best_way(int x, int y); 
   void show_maze(const vector<vector<int>>& v); 
   vector<vector<int>> maze; 
   int sx, sy, ex, ey, width, height, c; 
}; 
int Maze::count = 10000; 
vector<vector<int>> Maze::road = {{}}; 
void Maze::show_maze(const vector<vector<int>>& v) 
{ 
   cout << "Map : s.start e.end 0.wall 1.road 2.can_go 3.shortest_road" << endl; 
   for(int y=0; y<height; y++) { 
      for(int x=0; x<width; x++) { 
         if(x == sx && y == sy) cout << 's'; 
         else if(x == ex && y == ey) cout << 'e'; 
         else cout << v[y][x]; 
      } 
      cout << endl; 
   } 
} 
Maze::Maze(vector<vector<int>> v) 
{ 
   maze = v; 
   height = v.size(); 
   width = v[0].size(); 
   for(int y=0; y<height; y++) { 
      for(int x=0; x<width; x++) { 
         if(maze[y][x] == 8) { 
            sx = x; sy = y; 
            } else if(maze[y][x] == 9) { 
            ex = x; ey = y; 
            maze[y][x] = 1; 
         } 
      } 
   } 
   c = 0; 
} 

int Maze::get(int x, int y) const
{
	if(x < 0 || x >= width) return -1;
	if(y < 0 || y >= height) return -1;
	return maze[y][x];
}

void Maze::find_way(int x, int y) { 
   maze[y][x] = 2; 
   if(y > 0 && maze[y-1][x] == 1) find_way(x, y-1); 
   if(y+1 < height && maze[y+1][x] == 1) find_way(x, y+1); 
   if(x > 0 && maze[y][x-1] == 1) find_way(x-1, y); 
   if(x+1 < width && maze[y][x+1] == 1) find_way(x+1, y); 
} 
void Maze::best_way(int x, int y) 
{ 
   maze[y][x] = 3; 
   if(ex == x && ey == y) { 
      if(c < count) { 
         count = c; 
         road = maze; 
         if(c == abs(ex + ey - sx - sy) - 2) { 
            show_maze(road); 
            cout << "took " << c << "steps" << endl; 
            exit(0); 
         } 
      } 
      return; 
   } 
   if(y > 0 && maze[y-1][x] == 2) { 
//		if(get(x+1, y-1) == 3) return;
//		if(get(x-1, y-1) == 3) return;
//		if(get(x, y-2) == 3) return;
      Maze m(*this); 
      m.c++; 
      m.best_way(x, y-1); 
   } 
   if(y+1 < height && maze[y+1][x] == 2) { 
//		if(get(x+1, y+1) == 3) return;
//		if(get(x-1, y+1) == 3) return;
//		if(get(x, y+2) == 3) return;
      Maze m(*this); 
      m.c++; 
      m.best_way(x, y+1); 
   } 
   if(x > 0 && maze[y][x-1] == 2) { 
//		if(get(x-1, y+1) == 3) return;
//		if(get(x-1, y-1) == 3) return;
//		if(get(x-2, y) == 3) return;
      Maze m(*this); 
      m.c++; 
      m.best_way(x-1, y); 
   } 
   if(x+1 < width && maze[y][x+1] == 2) { 
//		if(get(x+1, y-1) == 3) return ;
//		if(get(x+1, y+1) == 3) return;
//		if(get(x+2, y) == 3) return;
      Maze m(*this); 
      m.c++; 
      m.best_way(x+1, y); 
   } 
} 
int main(int argc, char** argv) 
{ 
   if(argc < 3) { 
      cout << "usage : " << argv[0] << " width height" << endl; 
      return 0; 
   } 
   uniform_real_distribution<> nd(0,10); 
   knuth_b e(time(0)); 
   int w=atoi(argv[1]); 
   int h=atoi(argv[2]); 
   vector<int> v; 
   vector<vector<int>> m; 
   for(int y=0; y<h; y++) { 
      for(int x=0; x<w; x++) { 
         if(nd(e) > 4) v.push_back(1); 
         else v.push_back(0); 
      } 
      m.push_back(v); 
      v.clear(); 
   } 
  // m[nd(e)/10*h][nd(e)/10*w] = 8; 
  // m[nd(e)/10*h][nd(e)/10*w] = 9; 
   m[0][0]=8; m[h-1][w-1]=9;
   Maze maze {m}; 
   maze.show_maze(maze.maze); 
   maze.find_way(maze.sx, maze.sy); 
   maze.show_maze(maze.maze); 
   if(maze.maze[maze.ey][maze.ex] == 2) { 
      maze.best_way(maze.sx, maze.sy); 
      maze.show_maze(maze.road); 
      cout << "took " << maze.count << " steps" << endl; 
   } else cout << "cannot find the way " << endl; 
} 
