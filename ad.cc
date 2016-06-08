#include <iostream>
using namespace std;

int main()
{
	int price[5][5] = {
		{73, 13, 42, 68, 30},
		{45, 21, 65, 55, 90},
		{94, 93, 73, 90, 75},
		{24, 32, 74, 86, 70},
		{3, 32, 87, 23, 41}
	};
	bool select[5] = {false,false,false,false,false};
	int sum = 0, best = 10000, choice[5];
	int v[5] {};
	bool good = true;
	while(v[4] != 5) {
		v[0]++;
		for(int i=0; i<4; i++) {
			if(v[i] == 5) {
				v[i] = 0;
				v[i+1]++;
			}
		}
		for(int i=0; i<5; i++) select[v[i]] = true;
		for(int i=0; i<5; i++) if(!select[i]) good = false;
		if(good) {
			for(int i=0; i<5; i++) sum += price[v[i]][i];
			if(best > sum) {
				best = sum;
				for(int i=0; i<5; i++) choice[i] = v[i];
			}
		}
		for(int i=0; i<5; i++) select[i] = false;
		good = true;
		sum = 0;
	}
	cout << best << '=';
	for(int i=0; i<5; i++) cout << char('A' + choice[i]) << ' ';
	cout << endl;
}

