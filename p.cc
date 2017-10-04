#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int search(int * k, int to_search) {
for(int i=0; i<7; i++) {
if(k[i] == to_search) return i;
}
return 7;
}
int main(void)
{
int k[7];srand(time(NULL));
for(int i=0; i<7; i++) k[i] = rand()%100;
printf("7 random numbers are as follows.\n");
for(int i=0; i<7; i++) printf("%d ", k[i]);
printf("\n Enter number to search :");
int n;
scanf("%d", &n);
int idx = search(k, n);
if(idx != 7) printf(" Number %d is at %d th .", n, idx+1);
else printf(" Number %d does not exist .", n);
}
