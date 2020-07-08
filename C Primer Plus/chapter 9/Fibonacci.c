#include <stdio.h>
unsigned long Fibonacci(unsigned n);

int main(void)
{
    int number;
    printf("Enter a integer: ");
    while (scanf("%d",&number)==1)
    {
        printf("%lu",Fibonacci(number));
        putchar('\n');
        printf("Enter another integer. ");
    }
    printf("Done");
    return 0;
}
unsigned long Fibonacci(unsigned n)
{
    if (n<=2)
    return 1;
    else
    {
        return Fibonacci(n-1)+Fibonacci(n-2);
    }
    
}