#include <stdio.h>

int main(void)
{
    double i, terms;
    int prev =-1;
    float sum_1=0, sum_2=0;
    printf("Enter number of terms: ");
    scanf("%lf", &terms);
    for (i=1; i<=terms; i++)
        {
            prev *=-1;
            sum_1+=1/i;
            sum_2+=prev*(1/i);
        }
    printf("The sum of two arrays is %f in %lf terms.\n", sum_1+sum_2,terms);
    return 0;
            
}