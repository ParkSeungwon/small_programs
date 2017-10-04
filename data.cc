#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

template <typename T>
int max_element(T ar[], int sz) {
	T max = ar[0];
	int idx = 0;
	for(int i=0; i<sz; i++) {//sizeof(ar)/sizeof(T); i++) {
		if(max < ar[i]) {
			max = ar[i];
			idx = i;
		}
	}
	return idx;
}

int main()
{
	char ar[9] = "abfer";
	int ar2[6] = {1,2,34,3, 6,7};

	cout << ar[max_element(ar, sizeof(ar)/sizeof(ar[0]))] << endl;
	cout << ar2[max_element(ar2, 6)] << endl;

	cout << *min_element(ar, ar+5);
}

