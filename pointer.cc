#include <iostream>
using namespace std;
void score(int *x,int *y);
int main() {
int res;
int a,b;
 int *pN1=&a,*pN2=&b;
 
 score(pN1,pN2);
 
 cout << "더할 점수를 입력하십시오.\n";
 
 cin >> res;
 
 cout << "과목 1은(는)" << *pN1+res << "점이 되었습니다.\n"; 
 cout << "과목 2은(는)" << *pN2+res << "점이 되었습니다.\n"; 
 
 return 0;
}
void score(int *x,int *y) {
 int num1,num2;
 
 cout << "2 과목 분의 점수를 입력하십시오.\n";
 
 cin >> num1 ;
 cin >> num2 ;
 
 *x=num1;
 *y=num2;
}
