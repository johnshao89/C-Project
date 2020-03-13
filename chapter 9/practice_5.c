#include <stdio.h>

void order(double *x, double *y, double *z);
void swap(double *num1, double *num2);

int main(void)
{
    double num1, num2, num3;
    printf("Enter three numbers: ");
    scanf("%lf %lf %lf",&num1, &num2, &num3);
    order(&num1, &num2, &num3);
    printf("The ascending order is %lf %lf %lf.\n",num1, num2, num3);
    return 0;
}

void order(double *x, double *y, double *z)
{   
    if (*x>*y)
    swap(x,y);
    if (*y>*z);
    swap(y,z);
    if (*x>*z)
    swap(x,z);
}

void swap(double *num1, double *num2)
{
    double temp;
    if (*num1>*num2)
    {
        temp = *num1;
        *num1 = *num2;
        *num2 = temp;
    }
}