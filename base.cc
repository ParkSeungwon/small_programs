#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<map>
using namespace std;

int N, ff[500][6];
float avr[6];

float center(float t, int n) {
	float sum = 0;
	for(int i=0; i<N; i++) sum = ff[i][n] + ff[i][n+3] * t;
	return sum/N;
}

float distance(float t) {
	return sqrt(pow(avr[0] + t*avr[3], 2) + pow(avr[1] + t*avr[4], 2) + pow(avr[2] + t*avr[5], 2));
}

int main()
{
	ifstream f("b1.in");
	int C;
	f >> C;
	for(int cs = 0; cs<C; cs++) {
		f >> N;
		for(int n=0; n<N; n++) for(int i=0; i<6; i++) f >> ff[n][i];
		for(int i=0; i<6; i++) for(int n=0; n<N; n++) avr[i] += ff[n][i];
		for(int i=0; i<6; i++) avr[i] /= N;
		float t = 0;
		float tmp = distance(0);
		t = 10000;
		//while(distance(t) - tmp > 0.00001) if(distance(t) > 
		//float dis=100000;
		//float t;
	//	for(t=0; t<10000; t+=0.00001) {
	//		if(dis < distance(t)) break;
	//		else dis = distance(t);
	//	}
		cout << "Case #" << cs +1 << ": " << distance(t) << ' ' << t << endl;
	}
}



