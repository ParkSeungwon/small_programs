#include<stdio.h>

int sort(int* a, int* b) {
	if(*a > *b) {
		int tmp = *a;
		*a = *b;
		*b = tmp;
		return 1;
	} else return 0;
}

int sort3(int* a, int* b) {
	if((*a % 3 == 0) == (*b % 3 == 0)) return sort(a, b);
	else if(*b % 3 == 0) {
		int tmp = *a;
		*a = *b;
		*b = tmp;
		return 1;
	} else return 0;
}

int main()
{
	int arr[16] = {4,12,6,8,30,10,2,14,3,17,19,20,29,78,16,24};
	int sorted = 1;
	while(sorted) {
		sorted = 0;
		for(int i=0; i<15; i++) if(sort3(arr+i, arr+i+1)) sorted = 1;
	}
	for(int i=0; i<16; i++) printf("%d ", arr[i]);
}
