#include<stdio.h>
#include<stdlib.h>
using namespace std;

int main()
{
	int ar[10] = {2, 3, 6, 7, 9, 3, 2, 5, 10, 3};
	int max = 0, sum, s[3];
	for(int i=0; i<10; i++) {
		for(int j=0; j<10; j++) {
			for(int k=0; k<10; k++) {
				if(abs(i - k) > 1 && abs(j - k) > 1 && abs(i - j) > 1) {
					sum = ar[i] + ar[j] + ar[k];
					if(max < sum) {
						max = sum;
						s[0] = i; s[1] = j; s[2] = k;
					}
				}
			}
		}
	}
	printf("max = %d with C%d C%d C%d\n", max, s[0], s[1], s[2]);
}
	

