#include <stdio.h>

double min(double x, double y);

int main(void)
{
    double x, y, lesser;
    printf("Please enter two numbers: ");
    scanf("%lf %lf",&x,&y);
    lesser = min(x,y);
    printf("The less is %lf.\n",lesser);
    return 0;
}

double min(double x, double y)
{
    return x<y? x:y;
}