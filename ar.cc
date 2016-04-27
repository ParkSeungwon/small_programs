#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> arr(int i) 
{
	if(i <= 1) return {{1}};
	else if(i == 2) return {{1,1},{2}};
	else {
		vector<vector<int>> v1, v2;
		v1 = arr(i-1);
		for(auto& a : v1) a.push_back(1);
		v2 = arr(i-2);
		for(auto& a : v2) {
			a.push_back(2);
			v1.push_back(a);
		}
		return v1;
	}
}

int main()
{
	int n;
	vector<vector<int>> ar;
	cout << "number ? ";
	cin >> n;
	for(auto& a : arr(n)) {
		for(auto& b : a) cout << b;
		cout << endl;
	}

}


