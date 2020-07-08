#include <stdio.h>

void cube (float n);
int main(void)
{
    float num;
    printf("Enter a number: ");
    scanf("%f",&num);
    cube(num);
    return 0;
}

void cube(float n)
{
    printf("%.2f",n*n*n);
}