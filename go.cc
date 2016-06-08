#include <iostream>
#include <string>
using namespace std;

class Board
{
public:
	string board[9][9];
	Board() {
		for(int x = 1; x<8; x++) {
			board[x][0] =  "┳";
			board[x][8] =  "┻";
			for(int y=1; y<8; y++) board[x][y] =  "╋";
		}
		for(int y = 1; y<8; y++) {
			board[0][y] =  "┣";
			board[8][y] =  "┫";
		}
		board[0][0] =  "┏";
		board[8][0] =  "┓";
		board[0][8] =  "┗";
		board[8][8] =  "┛";
	}

	void show() {
		cout << " 1234567" << endl;
		for(int y=0; y<9; y++) {
			for(int x=0; x<9; x++) cout << board[x][y];
			cout << endl;
		}
	}

	void putblack(int x, int y) {
		board[x][y] = "●";
	}
	void putwhite(int x, int y) {
		board[x][y] =  "○";
	}
};


		
int main()
{
	Board b;
	b.show();
	b.putwhite(3,4);
	b.putblack(4,4);
	b.putwhite(2,2);
	b.putblack(0,3);
	b.show();
}

