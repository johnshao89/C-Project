#include<stdio.h>

int count=0;

void foo(void);

int main(void)
{
    int times;
    puts("Enter number of times to call foo:");
    while(scanf("%d", &times)==1)
    foo();
    printf("The foo has been called %d times.\n", count);
    return 0;
    
}

void foo(void)
{
    count++;
}