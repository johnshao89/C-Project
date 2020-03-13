#include <stdio.h>

void order(double *x, double *y);

int main(void)
{
    double num1, num2;
    printf("Enter three numbers: ");
    scanf("%lf %lf",&num1, &num2);
    order(&num1, &num2);
    printf("The ascending order is %lf %lf\n",num1, num2);
    return 0;
}

void order(double *x, double *y)
{   
    double temp;
    if (*x > *y)
    {
        temp = *x;
        *x = *y;
        *y = temp;
    }
    
}