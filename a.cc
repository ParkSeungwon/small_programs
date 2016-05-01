#include <stdio.h>
#include <math.h>
int main()
{
 double a, b, c,D;
 
 printf("계수 a를 입력하시오: ");
 scanf("%lf", &a);
 printf("계수 b를 입력하시오: ");
 scanf("%lf", &b);
 printf("계수 c를 입력하시오: ");
 scanf("%lf", &c);
 
 D = (b*b - 4 * a*c);
 if (D > 0) {
	printf("실근입니다.\n");
	printf("방정식의 근은 %f입니다.\n", (-b + sqrt(D)) / (2 * a));
	printf("방정식의 근은 %f입니다.\n", (-b - sqrt(D)) / (2 * a));
 } else if (D == 0) {
	printf("중근입니다.\n");
	printf("방정식의 근은 %f입니다.\n", (-b) / (2 * a));
 } else {
	double d1, d2;
	printf("허근입니다.\n");
	printf("실근이 존재하지 않음.\n");
	 
	d1 = -b / (2 * a);
	d2 = sqrt(-D) / (2 * a);
	printf("허근의 값은 %lf+%lfi\n",d1,d2);
	printf("허근의 값은 %lf-%lfi\n",d1,d2);
 }
 
 return 0;
}
