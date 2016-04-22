#include <iostream>
#include <cmath>
using namespace std;

int fact(int i) 
{
	if(i>1)	return fact(i-1) * i;
	else return 1;
}

int main()
{
	double sum = 1;
	int z;
	cout << "z = ? " ;
	cin >> z;
	for(int i=1; i<20; i++) sum += 1.0f/fact(i);
	cout << " e = " << sum << endl;
	double s = sum;
	for(int i=1; i<z; i++) sum *= s;
	cout << "e^z = " << sum << endl;

	float ohm[5] = {5.9, 11.4, 2.72, 1.72, 7.24};
	float f;
	int c=0, m;
	for(int i=0; i<=20; i++) {
		for(int j=0; j<=20-i; j++) {
			for(int k=0; k <= 20-i-j; k++) {
				for(int l=0; l <= 20-i-j-k; l++) {
					m = 20-i-j-k-l; 
					f = ohm[0] * i + ohm[1] * j + ohm[2] * k + ohm[3] * l + ohm[4] * m;
					f = f / 20;
					if(f >= 4.95 && f <= 5.05) {
						cout << "Zinc " << i*5 << " Tin " << j*5 << " Al " << k*5;
						cout << " Cu " << l*5 << " Ni " << m*5 << " ohm " << f << endl;
					}
				}
			}
		}
	}
}


