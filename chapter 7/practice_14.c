#include <stdio.h>

int main(void)
{
    double arr_1[8], arr_2[8],sum=0;
    int i,k;
    printf("Type 8 numbers for array 1: ");
    for (i=0; i<8; i++)
    {
        scanf("%lf",&arr_1[i]);
        for (k=0; k<=i; k++)
        {
            sum+=arr_1[k];
            
        }
        arr_2[i]=sum;
        printf("%lf\n",arr_2[i]);
        sum=0;
    }
    return 0;
}