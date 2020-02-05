#include <stdio.h>

int main(void)
{
    float num_1, num_2;
    printf("Enter number 1: ");
    while (scanf("%f", &num_1)==1)
    {
        printf("Enter number 2: ");
        scanf("%f", &num_2);
        printf("%f\n",(num_1-num_2)/(num_2*num_1));
        printf("Enter num 1: ");
    }
    return 0;
}