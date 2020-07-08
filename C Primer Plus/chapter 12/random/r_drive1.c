#include <stdio.h>
#include <stdlib.h>

extern void srand1(unsigned int x);
extern int rand1(void);

int main(void)
{
    int count;
    unsigned int seed;
    printf("Enter your choice for seed.\n");
    while(scanf("%u",&seed)==1)
    {
        srand1(seed); //shuffle the seed
        for (count =0; count <5; count++)
        printf("%d\n",rand1());
        printf("Enter next seed (q to exit):\n");
    }
    printf("Done\n");
    return 0;
}