#include <stdio.h>
int main(){
int a = 0;
int b = 0;
scanf("%d %d", &a, &b);
int sum = a + b ;
printf("sum = %d\n",sum);
// int c = scanf_s("%d");  scanf_s是vs的函数不是c本身的
// printf("%d",c);
return 0;
}