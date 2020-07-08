#include<stdio.h>

extern unsigned int srand1(unsigned int seed);
extern unsigned int rand1(void);

int main(void)
{
    unsigned int seed;
    int count;
    printf("Enter a integer for seek:\n");
    while(scanf("%u", &seed)==1)
    {
        srand1(seed);
        for (count =0; count<5; count++)
        printf("%u\n",rand1());
        printf("Enter next seed\n");
    }
    printf("Done!\n");
    return 0;
}

// to compile two .c files, could use gcc -include file1.c file2.c
// or gcc -o rename file1.c file2.c