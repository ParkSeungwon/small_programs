#include <iostream>
#include <cmath>
#define PRECISION 0.0001
using namespace std;

double mi(double (*func)(double), double x) {//x에서의 미분 
	double deltax = 1, ret;
	int count = 0;
	while(deltax > 0) {
		double tmp = (func(x+deltax) - func(x)) / deltax;
		deltax /= 2;
		if(abs(ret - tmp) < PRECISION) count++;
		else count = 0;
		ret = tmp;
		if(count > 5) break;
	}
	return ret;
}

double juk(double (*func)(double), double a, double b) {//a에서 b까지의 적분
	int count = 0;
	double tmp = 0, ret = 0;
	for(double deltax=b-a; deltax > 0; deltax /= 2) {
		for(double x=a; x<=b; x+=deltax) tmp += func(x) * deltax;
		if(abs(ret - tmp) < PRECISION) count++;
		else count = 0;
		ret = tmp;
		tmp = 0;
		if(count > 5) break;
	}
	return ret;
}

double f1(double x) {return sin(x);}//미적을 행할 함수
double f2(double x) {return x*x + 2*x + 3;}
double f3(double x) {return sqrt(4-2*cos(x)+1);}
double f4(double x) {return 400/x;}
double f5(double x) {return pow(3+exp(x),2);}
double normal(double x) {
	double sigma = 0.2/sqrt(100);;
	double m = 0;
	return 1/(sigma*sqrt(2*M_PI)) * exp(-(x-m)*(x-m)/(2*sigma*sigma)); 
}
int main()
{
	cout << mi(f1, M_PI) << endl;//sin함수의 3에서의 미분값 : -0.989
	cout << mi(f2, 3) << endl;//이차함수의 3에서의 미분값 : 8
	cout << juk(f1, 2, 4) << endl;//sin함수 2~4까지 적분 : 0.237
	//cout << juk(f4, 2, 4) << endl;//이차함수 2~4까지 적분 : 36.66
	//cout << juk(f5, 0, 2)*M_PI << endl;
	cout << 2 * juk(normal, 0, 0.03) << endl;
	//cout << juk(normal, -100, 100) << endl;
}




