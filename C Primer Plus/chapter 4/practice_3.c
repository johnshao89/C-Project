#include <stdio.h>

int main(void)
{
    float n;
    printf("Enter a float number: ");
    scanf("%f",&n);
    printf("%e\n",n);
    printf("%E\n",&n);
}