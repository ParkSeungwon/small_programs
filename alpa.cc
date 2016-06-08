#include<iostream>
#include<algorithm>
#include<random>
using namespace std;

int main()
{
	uniform_int_distribution<> d('a', 'z');
	random_device r;

	char c[100], ch;
	for(int i=0; i<100; i++) c[i] = d(r);
	for(auto& a : c) cout << a;
	cout << endl << "찾을 문자를 입력하세요.";
	cin >> ch;
	cout << count(c, c+100, ch) << "개의 " << ch << "가 있습니다." << endl;

	int a[3];
	int b[9] = {1,2,3,4,5,6,7,8,9};
	shuffle(b, b+9, r);
	int n = 0;
	while(n!=3) {
		n = 0;
		cout << endl << "숫자를 입력하세요" ;
		cin >> a[0] >> a[1] >> a[2];
		for(int i=0; i<3; i++) {
			if(find(a, a+3, b[i]) != a+3) n++;
		}
		cout << n << " strike " << endl;
	}

}
