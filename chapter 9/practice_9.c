#include<stdio.h>
#include <stdlib.h>

double xpow(double base, int exp);

int main(void)
{
    double base;
    int exp;
    printf("Enter an integer and its power: ");
    while((scanf("%lf %d",&base,&exp))==2)
        {
            printf("The %lf 's power of %d is %lf.\n",base,exp, xpow(base,exp));
            printf("Continue: ");
        }
    printf("Done.\n");
}

double xpow(double base, int exp)
{
    double sum;
    if (base ==0)
    return 0;
    else if (exp == 0)
    return 1;
    sum = base*xpow(base,abs(exp)-1);
    if (exp<0)
    sum =1/sum;
    return sum;
    
}
