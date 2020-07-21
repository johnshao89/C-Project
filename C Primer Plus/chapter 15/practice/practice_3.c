#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int bit_open(int);

int main(void)
{
    int input;
    int output;
    printf("Enter an integer to begin:");
    while(scanf("%d", &input)==1)
    {
        output = bit_open(input);
        printf("%d bits are open.\n", output);
        printf("Enter the next integer.");
    }
    puts("Done!");
    return 0;
}

int bit_open(int n)
{
    int count=0;
    int size = CHAR_BIT*sizeof(int);
    for(int i=0;i<size;i++,n>>=1)
    {
        if((n&01)==01)
        count++;
    }
    return count;
}