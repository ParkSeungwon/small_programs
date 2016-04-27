#include <iostream>
#include <cmath>
using namespace std;

bool verify(int sys, int num)
{
	while(num > 1) {
		if(num % 10 >= sys) return false;
		num /= 10;
	}
	return true;
}

long convertToDecimal(int sys, int num) 
{
	long sum = 0;
	for(int i=0; num > 0; i++) {
		sum += (num % 10) * pow(sys, i);
		num /= 10;
	}
	return sum;
}

long decimalToSys(int sys, int num)
{
	if(num < sys) return num;
	long ret = 1;
	int i, j;
	for(i = 1; pow(sys, i) <= num; i++) ret *= 10;
	for(j = 1; pow(sys, i-1) * j <= num; j++) ;
	ret *= j-1;
	num -= pow(sys, i-1) * (j-1);
	return ret + decimalToSys(sys, num);
}

int main()
{
	int sys, n1, n2;
	cout << "진법과 숫자 두 개를 입력하세요." << endl;
	cin >> sys >> n1 >> n2;
	if(!verify(sys, n1)) return -1;
	if(!verify(sys, n2)) return -1;
	long i1 = convertToDecimal(sys, n1);
	long i2 = convertToDecimal(sys, n2);

	cout << "n1 + n2 = " << decimalToSys(sys, i1 + i2) << endl;
	cout << "n1 - n2 = " << decimalToSys(sys, i1 - i2) << endl;
	cout << "n1 * n2 = " << decimalToSys(sys, i1 * i2) << endl;
	cout << "n1 / n2 = " << decimalToSys(sys, i1 / i2) << endl;
	cout << "sizeof long is " << sizeof(long) << endl;
	return 0;
}

