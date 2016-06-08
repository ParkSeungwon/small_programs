#include <iostream>
#define X 6
using namespace std;

int main()
{
	int v[100];
	int n;
	cin >> n;
	for(int i=0; i<n; i++) v[i] = 0;
	while(v[n-1] != X) {
		v[0]++;
		for(int i=0; i<n-1; i++) {
			if(v[i] == X) {
				v[i] = 0;
				v[i+1]++;
			}
		}
		cout << v[0];//실행할 문장 
	}
}


