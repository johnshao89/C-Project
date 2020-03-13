#include<stdio.h>

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
    double pow =1;
    int i;
    if (base ==0)
    return 0;
    else if (exp ==0)
    return base;
    else
    {
        if (exp > 0)
        {for (i=1;i<=exp;i++)
            pow*=base;}
        else
        {
            for (i=-1;i>=exp;i--)
            pow/=base;
        }
        return pow;
        
    }
    
}

