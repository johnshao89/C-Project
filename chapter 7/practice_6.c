#include <stdio.h>

int main(void)
{
    long long up_limit, bottom_limit, i;
    printf("Enter the up limit of an integer: ");
    while (scanf("%lld",&up_limit)==1)
        {
            printf("Enter the lower limit of an integer: ");
            scanf("%lld",&bottom_limit);
            for (i=bottom_limit;i<=up_limit;i++)
            printf("%lld  %lld  %lld\n", i, i*i, i*i*i);
            printf("Enter the up limit of an integer: ");
        }
    return 0;
}