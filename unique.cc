#include <memory>
using namespace std;
int main()
{
	unique_ptr<unique_ptr<int[]>[]> up(new unique_ptr<int[]>[30]);
	for(int i=0; i<30; i++) {
		up[i].reset(new int[40]);
	}
	for(int x=0; x<30; x++) {
		for(int y=0; y<40; y++) {
			up[x][y] = x + y;
		}
	}

}


