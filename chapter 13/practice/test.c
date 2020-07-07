#include<stdio.h>

void swap(int *x, int *y);

int main(void)
{
    int a =1;
    int b =2;
    swap(&a, &b);
    printf("a is %d, b is %d", a,b);
    return 0;
}

void swap(int *x, int *y)
{
    int *temp;
    temp = x;
    x =y;
    y =temp;
}