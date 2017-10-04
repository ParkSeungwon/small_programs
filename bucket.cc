#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
#include"listack.h"
using namespace std;

ostream& operator<<(ostream& o, pair<int, int> n)
{
	cout << '{' << n.first << ',' << n.second << '}';
}

const array<int, 3> capacity{3, 5, 8};
const array<int, 3> target{0, 2, 6};
array<int, 3> bucket{0, 0, 8};
array<int, 3> prev_state;
vector<array<int, 3>> v;
Listack<pair<int, int>> li;

void move(int from, int to) {
	if(bucket[from]) {
		int diff = capacity[to] - bucket[to];
		if(diff) {
			prev_state = bucket;
			if(diff < bucket[from]) {
				bucket[from] -= diff;
				bucket[to] = capacity[to];
			} else {
				bucket[to] += bucket[from];
				bucket[from] = 0;
			}
			if(find(v.begin(), v.end(), bucket) == v.end()) {
				v.push_back(bucket);
				li.push({from, to});
				//cout << pair<int,int>{from, to} << flush ;
			} else {
				bucket = prev_state;
				return;
			}
			if(bucket == target) {
				li.show();
				li.pop();
				return;
			}
			move(0, 1);
			move(0, 2);
			move(1, 0);
			move(1, 2);
			move(2, 0);
			move(2, 1);
			li.pop();
		}
	}
}

int main()
{
	move(2, 1);
	bucket = {0,0,8};
	v.clear();
	move(2, 0);
}

