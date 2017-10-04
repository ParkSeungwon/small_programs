#include<iostream>
#include<cstdio>
using namespace std;


void print(const char* arr, int n, int l) 
{
	int k = 0;
	for(int i=n; arr[i] != '\0'; i++) {
		cout << arr[i];
		k++;
	}
	for(int i=0; i<n; i++) cout << arr[i];
	cout << endl;
	if(n != l) print(arr, (n+1)%(n+k), l);
}

void print2(int* arr, int n)
{
	if(n > 10) return;
	int* ch = new int[n+1];
	for(int i=0; i <= n; i++) {
		ch[i] =  (i == 0 ? 0 : arr[i-1]) + (i == n ? 0 : arr[i]);
		cout << ch[i] << ' ';
	}
	cout << endl;
	print2(ch, n+1);
}

int get(int n, int x) {
	if(x == 1 || n == 1) return 1;
	if(x == n) return 1;
	return get(n-1, x-1)+ get(n-1, x);
}

int main()
{
	const char* ar = "dfsr4532w";

	for(int j=1; j<15; j++) {
		for(int i=1; i<=j; i++) cout << get(j, i) << ' ';
		cout << endl;
	}

	for(int a=3; a<10; a++) cout << a << ' ';
	int a, b;
	char c;

	scanf("%c%d%d", &c, &a, &b);
	cout << endl << c << ' '<< a << ' ' << b;
}
