#include <stdio.h>

double har_min(double x, double y);

int main(void)
{
    double x, y;
    printf("Enter two numbers: ");
    scanf("%lf %lf",&x,&y);
    printf("The harmonized mean is %lf.\n", har_min(x,y));
    return 0;
}


double har_min(double x, double y)
{
    return 2/(1/x + 1/y);
}