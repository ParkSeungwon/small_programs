#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
int main()
{
 int choice,num1,num2;
    float result;
    char math;
 printf("******공학용 계산기 프로그램******\n");
 printf("엄청난 계산량을 자랑하는 나노의 프로그램!\n");
 printf("먼저  방법을 설명합니다.\n");
 printf("1.원하는 숫자를 입력하세요!\n");
 printf("2.원하는 연산자를  입력하세요!\n");
 printf("3.계산값을 출력해 드립니다.\n");
 printf("그러면 시작합니다!\n");
 printf("******연산자 활용법 지침서!******\n");
 printf("덧셈+ 뺄셈- 곱셈* 나눗셈/ 나머지%");
 printf("절댓값| 제곱^ 제곱근r");
 printf("사인s 코사인c 탄젠트t 상용로그l 계승!\n");
 printf("사용할 연산이  오칙연산이면 1,그 외의 연산이면 2를 눌러주세요!\n");
 scanf("%d",&choice);
 if (choice==1)
 {
  printf("오칙연산을 선택하셨군요!\n");
  printf("첫번째 숫자를 입력해주세요.\n");
  scanf("%d",&num1);
  printf("두번째 숫자를 입력해주세요.\n");
  scanf("%d",&num2);
  fflush(stdin);
  printf("연산 방법을 입력해주세요.\n");
  //scanf("%c",math);
  cin >> math;
  switch (math)
  {
   case '+' : result=num1+num2;
   printf("결과는 %d입니다.\n",result);
   break;
   case '*' : result=num1*num2;
   printf("결과는 %d입니다.\n",result);
   break;
      case '-' : result=num1-num2;
   printf("결과는 %d입니다.\n",result);
   break;
   case '/' : result=num1/num2;
   printf("결과는 %d입니다.\n",result);
   break;
      case '%' : result=num1%num2;
   printf("결과는 %d입니다.\n",result);
   break;
   default :
   printf("올바른선택이 아닙니다!");
   exit(1);
  }
 }
 else
 {
  printf("오칙연산 외의 연산을 선택하셨군요!\n");
  printf("계산할  숫자를 입력해주세요!\n");
  scanf("%d",&num1);
  fflush(stdin);
  printf("연산 방법을 입력해주세요.\n");
  scanf("%c",math);
  switch (math)
  {
   case '|' : result=fabs(num1);
   printf("결과는 %d입니다.\n",result);
   break;
   case '^' : result=pow(num1,2);
   printf("결과는 %d입니다.\n",result);
   break;
   case 'r' : result=sqrt(fabs(num1));
   printf("결과는 %d입니다.\n",result);
   break;
   case 's' : result=sin(num1);
   printf("결과는 %d입니다.\n",result);
   break;
   case 'c' : result=cos(num1);
   printf("결과는 %d입니다.\n",result);
   break;
   case 't' : result=tan(num1);
   printf("결과는 %d입니다.\n",result);
   break;
   case 'l' : result=log10(fabs(num1));
   printf("결과는 %d입니다.\n",result);
   break;
   case '!' :
   result=1;
   int i;
   for (i=1;i<=num1;i++)
   {
    result*=i;
   }
   printf("결과는 %d입니다.\n",result);
      break;
      default :
      printf("올바른 선택이 아닙니다!");
      exit(1);
  }
  
 }
 return 0;
}
