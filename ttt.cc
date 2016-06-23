#include<iostream>
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

int main()
{
	const char* ar = "dfsr4532w";
	print(ar, 4, 3);
	cout << 1 << endl;
	int a[1] = {1};
	print2(a, 1);
}
