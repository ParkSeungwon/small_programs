#include <iostream>
#include <fstream>
using namespace std;

class Point
{
public:
	Point(int x=0, int y=0) : x_(x), y_(y) {}
	void setXY(int x, int y) { x_ = x; y_ = y; }
	void Print() { cout << '(' << x_ << ',' << y_ << ')'; }
	int x_, y_;
private:
};

class Data
{
public:
	Data() {
		ifstream f("point.dat");
		if(f.is_open()) {
			int x, y;
			for(int i=0; i<10; i++) {
				f >> x >> y;
				point_[i].setXY(x, y);
			}
			f.close();
		} else {
			ofstream of("point.dat");
			for(int i=0; i<20; i++) of << 0 << ' ';
			of.close();
		}
	}
	void Run() {
		bool exit = false;
		char c;
		int n, x, y;
		while(!exit) {
			cout << "1.show 2.edit 3.save 4.exit" << endl;
			cin >> c;
			switch(c) {
			case '1': 
				for(int i=0; i<10; i++) point_[i].Print(); 
				cout << endl;
				break;
			case '2': 
				cout << "enter : Nth x y" << endl;
				cin >> n >> x >> y;
				point_[n-1].setXY(x, y);
				break;
			case '3':
				{
					ofstream of("point.dat");
					for(int i=0; i<10; i++)
						of << point_[i].x_ << ' ' << point_[i].y_ << ' ';
				}
				break;
			default: exit = true;
			}
		}
	}
private:
	Point point_[10];
};

int main() 
{
	Data data;
	data.Run();
	return 0;
}


