#include<iostream>
#include<vector>
#include<algorithm>
#include<array>
using namespace std;

ostream& operator<<(ostream& o, array<int, 3> n)
{
	cout << '{' << n[0] << ',' << n[1] << ',' << n[2] << '}';
}

const array<int, 3> capacity{3, 5, 8};
const array<int, 3> target{0, 2, 6};
array<int, 3> bucket{0, 0, 8};
array<int, 3> prev_state;
vector<array<int, 3>> v;

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
			if(find(v.begin(), v.end(), bucket) == v.end()) v.push_back(bucket);
			else {
				bucket = prev_state;
				return;
			}
			if(bucket == target) {
				for(auto& a : v) cout << a;
				cout << endl;
				v.pop_back();
				bucket = v.back();
				return;
			}
			move(0, 1);
			move(0, 2);
			move(1, 0);
			move(1, 2);
			move(2, 0);
			move(2, 1);
			v.pop_back();
			bucket = v.back();
		}
	}
}

int main()
{
	v = {{0,0,8}};
	move(2, 1);
	bucket = {0,0,8};
	v = {{0,0,8}};
	move(2, 0);
}

