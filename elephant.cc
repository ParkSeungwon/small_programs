#include<stdio.h>

int len(const char* p) {
	for(int i=1; ; i++) if(*p++ == '\0') return i;
}

int main()
{
	for(int j=5; j>0; j--) {
		for(int i=0; i<j; i++) printf(" ");
		for(int i=j; i<6; i++) printf("%d", 6-i);
		printf("\n");
	}
}


