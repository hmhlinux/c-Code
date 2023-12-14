#include <stdio.h>
int main(){
    char ch = 'a';
    int age = 27;
    short num = 10;
    long long1 = 10;
    long long long2 = 20;
    float weight = 55.5;
    double d = 0.5;
    printf("%d\n",sizeof(char));           //1
    printf("%d\n",sizeof(int));            //4
    printf("%d\n",sizeof(short));          //2
    printf("%d\n",sizeof(long));           //4
    printf("%d\n",sizeof(long long));      //8
    printf("%d\n",sizeof(float));          //4
    printf("%d\n",sizeof(double));         //8
    printf("----------------------------\n");
    printf("%d\n",long2);      //20
    printf("%lf",weight);      //%lf double类型
printf("------------------------------------------\n");
    












    return 0;
}