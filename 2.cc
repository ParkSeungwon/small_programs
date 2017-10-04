#include<stdio.h>
void bin(int n) {
	if(!n) return;
	bin(n/2);
	printf("%d", n%2);
}

int main()
{
	bin(13);
}
