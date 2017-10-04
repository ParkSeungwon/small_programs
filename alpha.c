#include<stdio.h>
int main()
{
	char ch;
	int result;

	result = 'a' - 'A';

	while(1) {
		printf("소문자를 입력하시고\n");
		scanf("%c", &ch);

		if(ch == 'Q') break;
		if(ch < 'a' || ch > 'z') continue;
		ch -= result;
		printf("변환된 문자는 %c입니다.", ch);
	}
	return 0;
}
